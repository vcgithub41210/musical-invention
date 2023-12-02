/**
 * This is a program to demonstrate how to Handle Exceptions in Java
 * 
 * Errors occur during execution of a program due to wrong input, errors in code or other issues
 * When an error occurs in Java, the program is stopped and the error message is displayed. This is called throwing an exception
 * This prevents the program from being executed completely
 * There is a necessity to deal with these errors
 * We can manually handle these exceptions using certain keywords
 * 
 * try- this keyword is used to define a block in which we can test some sections of code for errors during execution
 * 
 * catch- this keyword is used to define a block right below the try block. This allows you to write the necessary code and instructions when the code inside the try block encounters an error
 * 
 * finally- this keyword is used to define a block in which all the code executes even if there is an error in the try block
 * There is a misconception with finally block.Even though the finally block executes even in presence of error in try block
 * it would stop executing if an error is encountered within the finally block itself
 * 
 * Exceptions are of many types;
 * Exceptions related to arithmetic operations are ArithmeticExceptions
 * Exceptions related to input or output are IOExceptions
 * Exceptions related to pointers can be NullPointerException and so on
 * 
 * In this program we demostrate the use of try and catch block to catch an error when a number is divided by zero
 * As we know division by zero is not possible and in any programming language division by zero throws and error
 * 
 * the division operation is performed inside the try block to test for exceptions
 * the possible exception due to division by zero is caught by the catch block and the code inside the catch block is executed
 * 
 * the finally block gets executed regardless of errors
 * 
 * Note that there is the usage of ArithmeticException in the catch block parameter section, this is so that you can catch a specific Exception in the try block
 * It can also be replaced with "Exception e". This will help to catch any error that occurs in the try block
 * Note that there is the usage of printStackTrace() function
 * The printStackTrace() method in Java is a tool used to handle exceptions and errors.
 * It is a method of Java's throwable class which prints the throwable along with other details like the line number and class name where the exception occurred.
 * printStackTrace() is very useful in diagnosing exceptions.
 */

import java.io.*;
import java.util.Scanner;

class Exception{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int x = 1;
        while(x!=2){
            System.out.println("Enter the dividend: ");
            int dividend = sc.nextInt();
            int divisor = sc.nextInt();
            try{
                int result = dividend/divisor;
                System.out.println("The quotient of the resulting division is: "+result);
            }
            catch(ArithmeticException e){
                System.out.println("An error has occured! It seemed like you tried to divide by zero..");
                e.printStackTrace();
            }
            finally{
                System.out.print("Do you want to try again? => (1)Yes,(2)No : ");
                x = sc.nextInt();
                while(x == 2){
                    break;
                }
            }
        }
    }
}

//sample output
/*
Enter the dividend: 
12
4
The quotient of the resulting division is: 3
Do you want to try again? => (1)Yes,(2)No : 1
Enter the dividend: 
50
5
The quotient of the resulting division is: 10
Do you want to try again? => (1)Yes,(2)No : 1
Enter the dividend: 
8
0
An error has occured! It seemed like you tried to divide by zero..
java.lang.ArithmeticException: / by zero
        at Exception.main(Exception.java:47)
Do you want to try again? => (1)Yes,(2)No : 2
*/