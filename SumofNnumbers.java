import java.io.*;
import java.util.Scanner;

class SumofNnumbers{
	public static int recursion(int number)
	{
		if(number == 0)return 0;
		return number + recursion(number-1);
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the number of terms: ");
		int number = sc.nextInt();
		int sum = recursion(number);
		System.out.println("***Sum of first "+number+" numbers***");
		System.out.println(sum);
	}
}