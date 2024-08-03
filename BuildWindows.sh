rm -rf build
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE=toolchains/toolchain-mingw-win32.cmake ..
cmake --build .
