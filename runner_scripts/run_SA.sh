#!/bin/bash
set -x

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
        BS_X=128
        BS_Z=1
        BS_Y=8
        if [[ "${NV_ARCH}" == "Hopper" ]]; then
        BS_X=128
        BS_Y=1
        BS_Z=1
        fi
        if [[ "${HIP_ARCH}" == "gfx90a" ]]; then
        BS_X=64
        BS_Y=4
        BS_Z=1
        fi
		if [[ "${HIP_ARCH}" == "gfx942" ]]; then
		BS_X=64
		BS_Y=8
		BS_Z=1
		fi
fi
export OMP_PROC_BIND=TRUE
current_dir=$(basename "$PWD")

# Check if the directory name contains "_sp"
precsuffix=""
if [[ "$current_dir" == *"_sp"* ]]; then
	precsuffix="_sp"
fi
for j in {1..4}
do
	if [ -n "$CPUTEST" ]; then
	OMP_NUM_THREADS=1 mpirun -np $physical_cores $bind_core ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sa_"$precsuffix"_mpi"$physical_cores"_icc_diag2
  if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun -np $logical_cores $bind_hwthread ./opensbli_mpi 320 320 320 -OPS_DIAGS=2>> sa_"$precsuffix"_mpi"$logical_cores"_icc_diag2
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sa_"$precsuffix"_mpi"$numa_domains"omp"$physical_cores_per_numa"_icc_diag2
  fi
	OMP_PROC_BIND=TRUE OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi 320 320 320 -OPS_DIAGS=2 >> sa_"$precsuffix"_mpi"$numa_domains"omp"$threads_per_numa"_icc_diag2
	fi
	if [ -n "$SYCL" ]; then
	mpirun -np $numa_domains $bind_numa ./opensbli_mpi_sycl_flat 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect >> sa_"$precsuffix"_mpisycl_flat_diag2
	mpirun -np $numa_domains $bind_numa ./opensbli_mpi_sycl_ndrange 320 320 320 -OPS_DIAGS=2 OPS_SYCL_DEVICE=$SYCL_DEVICE -gpudirect OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> sa_"$precsuffix"_mpisycl_ndrange_diag2
	fi
  if [ -n "$TILING" ]; then
	for i in "${array[@]}"
	do
	OMP_NUM_THREADS=1 mpirun -np $physical_cores $bind_core ./opensbli_mpi_tiled 320 320 320 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=$i >> sa_"$precsuffix"_mpi"$physical_cores"_tiled_"$i"MB_icc_diag2
	if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=1 mpirun -np $logical_cores $bind_hwthread ./opensbli_mpi_tiled 320 320 320 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=$i >> sa_"$precsuffix"_mpi"$logical_cores"_tiled_"$i"MB_icc_diag2
	fi
	done
	for i in "${array_mpiomp[@]}"
	do
	size_per_numa=$(echo "$i * $physical_cores_per_numa" | bc)
	OMP_PROC_BIND=spread OMP_NUM_THREADS=$physical_cores_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi_tiled 320 320 320 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=$size_per_numa >> sa_"$precsuffix"_mpi"$numa_domains"omp"$physical_cores_per_numa"_tiled_"$size_per_numa"MB_icc_diag2
	if [ "$logical_cores" -ne "$physical_cores" ]; then
	OMP_NUM_THREADS=$threads_per_numa mpirun -np $numa_domains $bind_numa ./opensbli_mpi_tiled 320 320 320 -OPS_DIAGS=2 OPS_TILING_MAXDEPTH=12 OPS_CACHE_SIZE=$size_per_numa >> sa_"$precsuffix"_mpi"$numa_domains"omp"$threads_per_numa"_tiled_"$size_per_numa"MB_icc_diag2
	fi
	done
	fi
	if [ -n "$ACCEL" ]; then
	./opensbli_"$ACCEL" 320 320 320 -OPS_DIAGS=2 $ACCEL_FLAGS OPS_BLOCK_SIZE_Z=$BS_Z OPS_BLOCK_SIZE_Y=$BS_Y OPS_BLOCK_SIZE_X=$BS_X >> sa_"$precsuffix"_"$ACCEL"_diag2
	fi
done
