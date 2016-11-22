SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_PROCESSOR armv6)



# where is the target environment

SET(GCC_PATH ../tools/arm-rpi-4.9.3-linux-gnueabihf)
#SET(CMAKE_FIND_ROOT_PATH ${GCC_PATH})
SET(CMAKE_PREFIX_PATH ${GCC_PATH})

# search for programs in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# for libraries and headers in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CMAKE_C_COMPILER   arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
set(CMAKE_STRIP        arm-linux-gnueabihf-strip)

#find_program(TEST ${CMAKE_C_COMPILER} PATH_SUFFIXES bin)
#message("kupa ${TEST}")