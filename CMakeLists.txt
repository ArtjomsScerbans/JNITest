cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(HelloJNI VERSION 1.0)

# Add JAVA support
find_package(Java REQUIRED)
include(UseJava)

# specify the C++ standard
add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)

# set JAVA_HOME directory
set(JAVA_HOME "/usr/lib/jvm/java-11-openjdk-amd64")

# set compiler flags
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(tutorial_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wshadow;-Wformat=2>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# add the JNIFunctions library
add_subdirectory(JNIFunctions)

# compile into a JAR
add_jar(HelloJNI HelloJNI.java)
