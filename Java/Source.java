import java.io.*;

class Source {
    public static int fib(int step,int index, int length,int[] memo) {
        if(step == 0 && index == 0) return 1;
        if(step == 0 && index != 0) return 0;
        if(index < 0 || index >= length) return 0;
        if (memo[step][index] != -1){
            return memo[step][index];
        }
        int value = 0;
        for(int i = index-1;i < index+2;i++)
        {
            value += fib(step-1,i,length,memo);
        }
        memo[step][index] = value;
        return value;
    }
    public static void main(String[] args){
        int[][] hash = new int[steps][length];
        for(int i = 0; i < steps;i++)
        {
            for(int j = 0; j < steps;j++){
                hash[i][j] = -1;
            }
        }
        int result = fib(4,0,2,hash);
        System.out.println(result);
    }
}