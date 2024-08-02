#include <jni.h>       // JNI header provided by JDK
#include <iostream>    // C++ standard IO header
#include "HelloJNI.h"
using namespace std;

JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv *env, jobject obj) {
   cout << "In C++, Saying Hello!" << endl;
}

JNIEXPORT jdouble JNICALL Java_HelloJNI_sum(JNIEnv *env, jobject obj, jint n1, jint n2) {
   jdouble result;
   cout << "In C++, the numbers are " << n1 << " and " << n2 << endl;
   result = ((jdouble)n1 + n2);
   return result;
}

JNIEXPORT jstring JNICALL Java_HelloJNI_sayHelloAndSayResponse(JNIEnv *env, jobject thisObj, jstring inJNIStr) {
   // Step 1: Convert the JNI String (jstring) into C-String (char*)
   const char *inCStr = env->GetStringUTFChars(inJNIStr, NULL);
   if (NULL == inCStr) return NULL;
 
   // Step 2: Perform its intended operations
   cout << "In C++, the received string is: " << inCStr << endl;
   env->ReleaseStringUTFChars(inJNIStr, inCStr);  // release resources
 
   // Prompt user for a C++ string
   string outCppStr;
   cout << "Enter a String: ";
   cin >> outCppStr;
 
   // Step 3: Convert the C++ string to C-string, then to JNI String (jstring) and return
   return env->NewStringUTF(outCppStr.c_str());
}
