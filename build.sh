#/usr/bin/bash

make clean
mkdir build
cd build
cmake ..
make -j8
cd ..
make all