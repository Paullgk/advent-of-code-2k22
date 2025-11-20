#!/bin/bash -ex
rm -rf build
mkdir build
cd build
cmake $1 ..
make
