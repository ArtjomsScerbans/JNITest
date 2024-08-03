# declare the library
add_library(JNIFunctions SHARED JNIFunctions.cpp NativeFunctions.cpp)

target_include_directories(JNIFunctions PUBLIC ${JNI_INCLUDE_DIRS})

# link JNIFunctions to tutorial_compiler_flags
target_link_libraries(JNIFunctions PUBLIC HelloJNI-native)
target_link_libraries(JNIFunctions PUBLIC tutorial_compiler_flags)


