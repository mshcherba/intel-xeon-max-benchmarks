#!/bin/bash
BASE="${1:-$(pwd)}"

# Install system dependencies
sudo apt-get update
sudo apt-get install -y cmake libopenmpi-dev openmpi-bin

wget https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_2/source/hdf5-1.12.2.tar.gz
tar xfv hdf5-1.12.2.tar.gz
cd hdf5-1.12.2/
CC=mpicc CXX=mpicxx ./configure --enable-parallel --prefix=$BASE/hdf5
make install -j20
make distclean
./configure --prefix=$BASE/hdf5-seq
make install -j20
cd ..
echo "export HDF5_INSTALL_PATH=${BASE}/hdf5"
echo "export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HDF5_INSTALL_PATH/lib"
#wget http://glaros.dtc.umn.edu/gkhome/fetch/sw/parmetis/parmetis-4.0.3.tar.gz
wget https://ftp.mcs.anl.gov/pub/pdetools/spack-pkgs/parmetis-4.0.3.tar.gz
tar xfv parmetis-4.0.3.tar.gz
cd parmetis-4.0.3/metis
make config prefix=$BASE/parmetis
make install -j20
cd ..
make config prefix=$BASE/parmetis cxx=mpicxx cc=mpicc
make install -j20
echo "export PARMETIS_INSTALL_PATH=${BASE}/parmetis"
cd ..
wget https://gitlab.inria.fr/scotch/scotch/-/archive/v6.1.3/scotch-v6.1.3.tar.gz
tar xfv scotch-v6.1.3.tar.gz
cd scotch-v6.1.3/src
cp Make.inc/Makefile.inc.x86-64_pc_linux2 Makefile.inc
sed -i 's/gcc/mpicc/g' Makefile.inc
sed -i 's/-DCOMMON_PTHREAD//g' Makefile.inc
sed -i 's/-DSCOTCH_PTHREAD//g' Makefile.inc
sed -i 's/-DIDXSIZE64/-DIDXSIZE32/g' Makefile.inc
mkdir -p $BASE/ptscotch/lib
mkdir -p $BASE/ptscotch/include
make -j20
make ptscotch -j20
cp ../lib/*sc* $BASE/ptscotch/lib
cp ../include/*sc* $BASE/ptscotch/include
echo "export PTSCOTCH_INSTALL_PATH=${BASE}/ptscotch"
