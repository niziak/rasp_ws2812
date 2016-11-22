clean() {
{ 
    find -name CMakeCache.txt -a -type f -print ; find -name CMakeFiles -type d -print; find -name cmake_install.cmake ; } | xargs rm -rf
    rm -rf build_ras
    rm -rf build_simp
}