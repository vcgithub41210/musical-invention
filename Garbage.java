import java.io.*;
import java.util.*;

class x{
    int y;
}
class garb{
    public static void main(String args[]){
        Runtime r = Runtime.getRuntime();
        long mem1,mem3,mem2;
        System.out.println("total memory: " + r.totalMemory());
        mem1 = r.freeMemory();
        System.out.println("freememory: "+mem1);
        Scanner sc = new Scanner(System.in);
        int z = sc.nextInt();
        int a[] = new int[z];
        for(int i = 1;i<10;i++)
        {
            x y = new x();
        }
        Runtime g = Runtime.getRuntime();
        mem2 = g.freeMemory();
        System.out.println("freememory: " + mem2);
        r.gc();
        mem3 = r.freeMemory();
        System.out.println("freememory after garbage collection: "+mem3);
    }
}