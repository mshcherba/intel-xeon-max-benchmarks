#!/bin/bash
BASE=`pwd`
source source_hip
export OP_AUTO_SOA=1
if [ -z "$2" ]; then
  set -- "$1" "all"
fi

if [ "$2" == "all" ] || [ "$2" == "ops" ]; then
cd $BASE/OPS/ops/c
make $1 -j8
cd $BASE/OPS/apps/c/CloverLeaf
make cloverleaf_"$1" -B &
cd $BASE/OPS/apps/c/CloverLeaf_3D
make cloverleaf_"$1" -B &
cd $BASE/apps/rtm/
make rtm_"$1" -B &
cd $BASE/apps/TGV_StoreAll
make opensbli_"$1" -B &
cd $BASE/apps/TGV_StoreNone
make opensbli_"$1" -B &
cd $BASE/apps/TGV_mixed/TGsym_DP
make opensbli_"$1" -B &
cd $BASE/apps/TGV_mixed/TGsym_SP
make opensbli_"$1" -B &
cd $BASE/apps/TGV_mixed/TGsym_HP
make opensbli_"$1" -B &
cd $BASE/apps/TGV_mixed/TGsym_SPDP
make opensbli_"$1" -B &
cd $BASE/apps/TGV_mixed/TGsym_HPSP
make opensbli_"$1" -B &
cd $BASE/apps/ops_so08
make wave-propagation_"$1" -B &
wait
fi
if [ "$2" == "all" ] || [ "$2" == "op2" ]; then
cd $BASE/OP2-Common/op2/
make config
make $1
make openmp4 -j8
cd $BASE/apps/MG-CFD-app-OP2/
./translate2op2.sh
make $1
cd $BASE/apps/volna/sp
./translate2op2.sh
make volna_"$1"
fi
if [ "$2" == "all" ] || [ "$2" == "other" ]; then
cd $BASE/apps/miniBUDE/$1
make TARGET=INTEL
mv bude bude_"$1"
cd $BASE/apps/miniWeather/miniWeather-omp
make DEVICE=gpu -B
mv main main_"$1"
fi
