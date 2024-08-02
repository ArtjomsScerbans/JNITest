#include <iostream>    // C++ standard IO header
#include <jni.h>   
#include "HelloJNI.h"
using namespace std;

void sayHello() {
   cout << "In C++, Saying Hello!" << endl;
}

double sum(int n1, int n2) {
   double result;
   cout << "In C++, the numbers are " << n1 << " and " << n2 << endl;
   result = ((double)n1 + n2);
   return result;
}

jstring sayHelloAndSayResponse(JNIEnv *env, jstring inJNIStr) {
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