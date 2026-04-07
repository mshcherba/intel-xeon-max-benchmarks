#!/bin/bash
export BASE=`pwd`
source source_intel
source detect_hardware.sh
export OMP_PROC_BIND=TRUE
export SYCL_DEVICE=1
#these are for baskerville
#module purge; module load baskerville
#module load bask-apps/test
#module load HDF5/1.10.7-iimpi-2021a
#export SYCL=1
# Intel Xeon Max 9462 — CPU only (HBM, no GPU)
export ACCEL=mpi
export ACCEL_FLAGS=""
export GPU=0
export CPUTEST=1
#export TILING=1
#export RAPL_PATH="/sys/devices/virtual/powercap/intel-rapl/intel-rapl:0/energy_uj"
#export RAPL_DRAM_PATH="/sys/devices/virtual/powercap/intel-rapl/intel-rapl:0/intel-rapl:0:0/energy_uj"

export BS_X=128
export BS_Y=1
export BS_Z=1

#if $1 is not set, set it to all
if [ -z "$1" ]; then
  set -- "all"
fi

if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "c2d" ]; then
cd $BASE/OPS/apps/c/CloverLeaf
$BASE/runner_scripts/run_cloverleaf.sh
fi

if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "c3d" ]; then
cd $BASE/OPS/apps/c/CloverLeaf_3D
$BASE/runner_scripts/run_cloverleaf3d.sh
fi
if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "rtm" ]; then
cd $BASE/apps/rtm
$BASE/runner_scripts/run_rtm.sh
fi

if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "so08" ]; then
cd $BASE/apps/ops_so08
$BASE/runner_scripts/run_so08.sh
fi
if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "sa" ]; then
cd $BASE/apps/TGV_StoreAll
$BASE/runner_scripts/run_SA.sh
fi
if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "sn" ]; then
cd $BASE/apps/TGV_StoreNone
$BASE/runner_scripts/run_SN.sh
fi
if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "sa_sp" ]; then
cd $BASE/apps/TGV_StoreAll_sp
$BASE/runner_scripts/run_SA.sh
fi
if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "sn_sp" ]; then
cd $BASE/apps/TGV_StoreNone_sp
$BASE/runner_scripts/run_SN.sh
fi

if [ "$1" == "all" ] || [ "$1" == "ops" ] || [ "$1" == "sbli_mixed" ]; then
cd $BASE/apps/TGV_mixed/TGsym_DP
$BASE/runner_scripts/run_mixed.sh
cd $BASE/apps/TGV_mixed/TGsym_SP
$BASE/runner_scripts/run_mixed.sh
cd $BASE/apps/TGV_mixed/TGsym_HP
$BASE/runner_scripts/run_mixed.sh
cd $BASE/apps/TGV_mixed/TGsym_SPDP
$BASE/runner_scripts/run_mixed.sh
cd $BASE/apps/TGV_mixed/TGsym_HPSP
$BASE/runner_scripts/run_mixed.sh
fi

if [ "$1" == "all" ] || [ "$1" == "op2" ] || [ "$1" == "mgcfd" ]; then
cd $BASE/apps/Rotor37_8M
$BASE/runner_scripts/run_mgcfd.sh
fi
if [ "$1" == "all" ] || [ "$1" == "op2" ] || [ "$1" == "volna" ]; then
cd $BASE/apps/volna/sp
$BASE/runner_scripts/run_volna.sh
fi
if [ "$1" == "all" ] || [ "$1" == "bude" ]; then
cd $BASE/apps/miniBUDE
$BASE/runner_scripts/run_bude.sh
fi
if [ "$1" == "all" ] || [ "$1" == "miniweather" ]; then
cd $BASE/apps/miniWeather
$BASE/runner_scripts/run_miniweather.sh
fi
