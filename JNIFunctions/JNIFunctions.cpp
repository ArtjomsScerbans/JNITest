#include <jni.h>       // JNI header provided by JDK
#include <iostream>    // C++ standard IO header
#include "JNIFunctions.h"  // Generated
using namespace std;

// Implementation of the native method sayHello()
JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
	cout << "Hello World from C++!" << endl;
   return;
}

// Implementation of the native method sumTwoNumbers()
JNIEXPORT void JNICALL Java_HelloJNI_sumTwoNumbers(JNIEnv *env, jobject thisObj) {
	cout << "Sum of 2 and 3 is " << 2 + 3 << endl;
   return;
}