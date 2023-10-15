import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

class Tribonacci{
    public static int trifib(int n,HashMap<Integer, Integer> memo){
        if (n==0||n==1) return 0;
        if(n==2) return 1;

        if (memo.containsKey(n)){
            return memo.get(n);
        }

        int value = trifib(n-1,memo) + trifib(n-2,memo) + trifib(n-3,memo);
        memo.put(n,value);
        System.out.println(memo);
        return value;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the term to be obtained: ");
        int term = sc.nextInt();
        System.out.println(trifib(term, new HashMap<>()));
    }
}