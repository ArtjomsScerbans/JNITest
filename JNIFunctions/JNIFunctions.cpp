#include <jni.h>       // JNI header provided by JDK
#include "HelloJNI.h"
#include <iostream>    // C++ standard IO header
#include "NativeFunctions.h"

using namespace std;

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject obj) {
   sayHello();
}

JNIEXPORT jdouble JNICALL Java_HelloJNI_sum(JNIEnv *env, jobject obj, jint n1, jint n2) {
   jdouble result = ((jdouble)sum(n1, n2));
   return result;
}

JNIEXPORT jstring JNICALL Java_HelloJNI_sayHelloAndSayResponse(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
   return sayHelloAndSayResponse(env, inJNIStr);
}
