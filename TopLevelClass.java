public class TopLevelClass {
    static {
        System.loadLibrary("JNIFunctions"); 
     }
         
    public static void main(String[] args) {
        // calling sum
        System.out.println("In Java, the sum is " + new HelloJNI().sum(2, 3));
        System.out.println();
        // calling sayHello with response
        String result = new HelloJNI().sayHelloAndSayResponse("Hello from Java");
        System.out.println("In Java, the returned string is: " + result);
        System.out.println();
        // calling simply sayHello without response (returns void)
        new HelloJNI().sayHello();
      }
}
