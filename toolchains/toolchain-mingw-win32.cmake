# the name of the target operating system
set(CMAKE_SYSTEM_NAME Windows)

# which C and C++ compiler to use
set(CMAKE_C_COMPILER /usr/bin/x86_64-w64-mingw32-gcc-win32)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++-win32)

# location of the target environment
set(CMAKE_FIND_ROOT_PATH /usr/x86_64-w64-mingw32)

# adjust the default behavior of the FIND_XXX() commands:
# search for headers and libraries in the target environment,
# search for programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)