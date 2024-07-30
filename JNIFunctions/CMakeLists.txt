# declare the library
add_library(JNIFunctions SHARED JNIFunctions.cpp)

# state include directories where to find jni.h and other JNI headers
target_include_directories(JNIFunctions PUBLIC
                           "${JAVA_HOME}/include"
                           "${JAVA_HOME}/include/linux"
                           )

# link JNIFunctions to tutorial_compiler_flags
target_link_libraries(JNIFunctions PUBLIC tutorial_compiler_flags)
