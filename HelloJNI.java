public class HelloJNI {  
    static {
       System.loadLibrary("JNIFunctions"); 
    }

    // Declare instances of two native methods which receive no parameter and returns void
    private native void sayHello();
    private native void sumTwoNumbers();
  
    public static void main(String[] args) {
       new HelloJNI().sayHello(); 
       new HelloJNI().sumTwoNumbers(); 
    }
 }