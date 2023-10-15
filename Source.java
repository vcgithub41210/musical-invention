import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

class Source {
    public static int fib(int n,HashMap<Integer, Integer> memo) {
        if(n ==0 || n==1){
            return n;
        }
        if (memo.containsKey(n)){
            return memo.get(n);
        }
        int result =  fib(n-1, memo) + fib(n-2, memo);
        memo.put(n,result);
        return result;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the the term to be obtained: ");
        int n = sc.nextInt();
        int result = fib(n, new HashMap<>());
        System.out.println("The value is: "+result);
    }
}