#/usr/bin/bash

make clean
mkdir build
cd build
cmake ..
make -j
cd ..
make all