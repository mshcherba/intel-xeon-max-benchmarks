#!/bin/bash
set -x
sed -i "s/end_step=.*/end_step=50/g" clover.in

# Check if the CACHE_SIZES environment variable is set
if [ -z "$CACHE_SIZES_MPI" ]; then
    export CACHE_SIZES_MPI="0.4,0.7,1,2"
fi
if [ -z "$CACHE_SIZES_MPIOMP" ]; then
    export CACHE_SIZES_MPIOMP="3,4,6,8"
fi
IFS=',' read -ra array <<< "$CACHE_SIZES_MPI"
IFS=',' read -ra array_mpiomp <<< "$CACHE_SIZES_MPIOMP"


if [ -n "$GPU" ]; then
        BS_X=64
        BS_Z=1
        BS_Y=4
        if [[ "${NV_ARCH}" == "Hopper" ]]; then
        BS_X=16
        BS_Y=4
        BS_Z=4
        fi
        if [[ "${HIP_ARCH}" == "gfx90a" ]]; then
        BS_X=64
        BS_Y=4
        BS_Z=4
        fi
		if [[ "${HIP_ARCH}" == "gfx942" ]]; then
		BS_X=32
		BS_Y=2
		BS_Z=16
		fi
fi
sizes=( 408 )
for i in "${sizes[@]}"
do
	sed -i "s/x_cells=.*/x_cells=$i/g" clover.in
	sed -i "s/y_cells=.*/y_cells=$i/g" clover.in
	sed -i "s/z_cells=.*/z_cells=$i/g" clover.in
	for j in {1..4}
	do
		if [ -n "$CPUTEST" ]; then
		OMP_NUM_THREADS=1 mpirun  -np $physical_cores $bind_core ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$physical_cores"_icx_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
		OMP_NUM_THREADS=1 mpirun  -np $logical_cores $bind_hwthread ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$logical_cores"_icx_diag2
		OMP_NUM_THREADS=$threads_per_numa OMP_PROC_BIND=TRUE mpirun -np $numa_domains  $bind_numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$numa_domains"omp"$threads_per_numa"_icx_diag2
  fi
		OMP_NUM_THREADS=$physical_cores_per_numa OMP_PROC_BIND=spread mpirun -np $numa_domains  $bind_numa ./cloverleaf_mpi -OPS_DIAGS=2 >> c3d_mpi"$numa_domains"omp"$physical_cores_per_numa"_icx_diag2
		fi
		if [ -n "$TILING" ]; then
		for i in "${array[@]}"
		do
		OMP_NUM_THREADS=1 mpirun -np $physical_cores $bind_core ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=$i >> c3d_mpi"$physical_cores"_tiled_"$i"MB_icc_diag2
		if [ "$logical_cores" -ne "$physical_cores" ]; then
		OMP_NUM_THREADS=1 mpirun -np $logical_cores $bind_hwthread ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=$i >> c3d_mpi"$logical_cores"_tiled_"$i"MB_icc_diag2
		fi
		done
		for i in "${array_mpiomp[@]}"
		do
		size_per_numa=$(echo "$i * $physical_cores_per_numa" | bc)
		OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=$size_per_numa >> c3d_mpi"$numa_domains"omp"$physical_cores_per_numa"_tiled_"$size_per_numa"MB_icc_diag2
		if [ "$logical_cores" -ne "$physical_cores" ]; then
		OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_tiled -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=6 OPS_CACHE_SIZE=$size_per_numa >> c3d_mpi"$numa_domains"omp"$threads_per_numa"_tiled_"$size_per_numa"MB_icc_diag2
		fi
		done
		fi
		if [ -n "$SYCL" ]; then
		mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_flat -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=1 OPS_BLOCK_SIZE_Y=1 >> c3d_mpisycl_flat_diag2
		mpirun -np $numa_domains $bind_numa ./cloverleaf_mpi_sycl_ndrange -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> c3d_mpisycl_ndrange_diag2
		fi
		if [ -n "$ACCEL" ]; then
			./cloverleaf_"${ACCEL}" -OPS_DIAGS=2 OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X $ACCEL_FLAGS >> c3d_"${ACCEL}"_diag2
		fi
	done
done
