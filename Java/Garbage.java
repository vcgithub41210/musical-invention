/**
 * This program is used to demonstrate garbage collection
 * Issues created by beginners to learning a language is creating excess memory and not using memory efficiently
 * A program is considered Efficient if it makes use of memory in the right way
 * The memory created during execution may become unused and need to be removed
 * In many languages
 * Unlike in other languages, in Java the JVM automatically does the garbage collection
 * garbage collection is done to those objects that no longer have a reference(they are assigned to null)
 * garbage collection can also be done manually by calling the System.gc() method
 * This does not actually removes any garbage and reclaims memory but instead suggests JVM that this is the moment to collect garbage
 * Hence calling the System.gc() function does not always remove garbage
 */

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

//sample output
/*
total memory: 130023424
freememory: 128532256
1000
freememory: 128083448
freememory after garbage collection: 7491416
*/