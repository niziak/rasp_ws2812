#!/bin/bash -eux
. ./func.sh

clean

# Out of source build
mkdir -p build_rasp
(cd build_rasp && cmake ../src --debug-output -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-arm-linux-gnueabi.cmake)
(cd build_rasp && make VERBOSE=1)

mkdir -p build_sim
(cd build_sim && cmake ../src --debug-output)
(cd build_sim && make VERBOSE=1)


# --trace
# -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-arm-linux-gnueabi.cmake

