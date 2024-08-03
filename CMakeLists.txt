cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(HelloJNI VERSION 1.0)

# Add Java support
find_package(Java REQUIRED)
find_package(JNI)
include(UseJava)

# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# set compiler flags
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wshadow;-Wformat=2>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/x86_64/${CMAKE_SYSTEM_NAME})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/x86_64/${CMAKE_SYSTEM_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/x86_64/${CMAKE_SYSTEM_NAME})

add_jar(HelloJNI HelloJNI.java TopLevelClass.java ENTRY_POINT TopLevelClass.java GENERATE_NATIVE_HEADERS HelloJNI-native OUTPUT_DIR ${PROJECT_BINARY_DIR}/jar)

# add the JNIFunctions library
add_subdirectory(JNIFunctions)
