import java.io.*;
import java.util.Scanner;

class Factorial
{
	public static int recursion(int number){
		if(number <= 1) return 1;
		return number * recursion(number-1);	
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number: ");
		int number = sc.nextInt();
		int factorial = recursion(number);
		System.out.println("***Factorial of " + number + " ***");
		System.out.println(factorial);
	}
}