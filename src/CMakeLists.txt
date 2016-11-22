cmake_minimum_required (VERSION 3.0)

# Toolchain set has to be before project()
#set (CMAKE_TOOLCHAIN_FILE cmake/toolchain-arm-linux-gnueabi.cmake)

project (ws2812 C)

SET(CMAKE_VERBOSE_MAKEFILE ON)


set (ws2812_VERSION_MAJOR 0)
set (ws2812_VERSION_MINOR 1)

configure_file (
    "version.h.in"
    "${PROJECT_BINARY_DIR}/version.h"
)
include_directories ("${PROJECT_BINARY_DIR}")

#set(COMMON_SOURCES main.c)
set(TARGET_SOURCES main.c)
set(TEST_SOURCES main.c)



IF(CMAKE_CROSSCOMPILING)
    add_executable(ws2812 ${COMMON_SOURCES} ${TARGET_SOURCES})
    target_include_directories (ws2812 PUBLIC rpi_ws281x)
    include(rpi_ws281x.cmake)
    target_link_libraries (ws2812 rpi_ws281x)
ENDIF(CMAKE_CROSSCOMPILING)

IF (NOT CMAKE_CROSSCOMPILING)
    add_executable(sim2812 ${COMMON_SOURCES} ${TARGET_SOURCES})
    target_include_directories (sim2812 PUBLIC rpi_ws281x)
    target_include_directories (sim2812 PUBLIC sim_ws281x)
    add_subdirectory (sim_ws281x)
    target_link_libraries (sim2812 sim_ws281x)
ENDIF(NOT CMAKE_CROSSCOMPILING)


#add_executable(ws2812t ${COMMON_SOURCES} ${TEST_SOURCES})
#add_custom_target()