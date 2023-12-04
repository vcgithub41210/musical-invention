import java.io.*;
 
public class MultiThread {
    static int num = 1;

   public static class Thread1 extends Thread {
       public void run() {
           while(true) {
               try {
                  Thread.sleep(1000);
                  num += 1;
               } catch (InterruptedException e) {
                  e.printStackTrace();
               }
           }
       }
   }
 
   public static class Thread2 extends Thread {
       public void run() {
           while(true) {
               if((num)%2 == 0)
                  System.out.println(num * num);
                try {
                  Thread.sleep(1000);
               } catch (InterruptedException e) {
                  e.printStackTrace();
               }
           }
       }
   }
 
   public static class Thread3 extends Thread {
       public void run() {
           while(true) {
               if((num)%2 != 0)
                  System.out.println(num*num*num);
                try {
                  Thread.sleep(1000);
               } catch (InterruptedException e) {
                  e.printStackTrace();
               }
           }
       }
   }
 
   public static void main(String args[]) {
       Thread1 t1 = new Thread1();
       Thread2 t2 = new Thread2();
       Thread3 t3 = new Thread3();
       t1.start();
       t2.start();
       t3.start();
   }
}

//sample output
/*
1
4
27
16
125
36
343
64
729
100
*/