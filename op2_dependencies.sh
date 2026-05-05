#!/bin/bash
BASE="${1:-$(pwd)}"

# 1. Install system dependencies
sudo apt-get update
sudo apt-get install -y cmake libopenmpi-dev openmpi-bin python3-clang python3-pcpp python3-cached-property python3-fparser python3-sympy \
    g++-14 python3.12-venv gnuplot

# 2. Intel OneAPI Installation
wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB | sudo gpg --dearmor | sudo tee /usr/share/keyrings/oneapi-archive-keyring.gpg > /dev/null
echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" | sudo tee /etc/apt/sources.list.d/oneAPI.list
sudo apt-get update
sudo apt-get install -y intel-oneapi-compiler-dpcpp-cpp intel-oneapi-compiler-fortran intel-oneapi-mkl intel-oneapi-mpi-devel

# 3. Source OneAPI for building dependencies
source /opt/intel/oneapi/setvars.sh --force
export OMPI_CC=icx
export OMPI_CXX=icpx

# 4. HDF5 Installation
wget https://hdf-wordpress-1.s3.amazonaws.com/wp-content/uploads/manual/HDF5/HDF5_1_12_2/source/hdf5-1.12.2.tar.gz
tar xfv hdf5-1.12.2.tar.gz
cd hdf5-1.12.2/
CC=mpicc CXX=mpicxx ./configure --enable-parallel --prefix=$BASE/hdf5
make install -j$(nproc)
make distclean
./configure --prefix=$BASE/hdf5-seq
make install -j$(nproc)
cd ..
rm -rf hdf5-1.12.2 hdf5-1.12.2.tar.gz

# 5. ParMETIS Installation
wget https://ftp.mcs.anl.gov/pub/pdetools/spack-pkgs/parmetis-4.0.3.tar.gz
tar xfv parmetis-4.0.3.tar.gz
cd parmetis-4.0.3/metis
make config prefix=$BASE/parmetis
make install -j$(nproc)
cd ..
make config prefix=$BASE/parmetis cxx=mpicxx cc=mpicc
make install -j$(nproc)
cd ..
rm -rf parmetis-4.0.3 parmetis-4.0.3.tar.gz

# 6. PT-Scotch Installation
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
make -j$(nproc)
make ptscotch -j$(nproc)
cp ../lib/*sc* $BASE/ptscotch/lib
cp ../include/*sc* $BASE/ptscotch/include
cd ../..
rm -rf scotch-v6.1.3 scotch-v6.1.3.tar.gz

echo "All dependencies installed in $BASE"
