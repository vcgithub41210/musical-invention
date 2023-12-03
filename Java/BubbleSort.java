import java.io.*;
import java.util.Scanner;

class Array{
    int size;
    int[] arr;
    Array(int size){
        this.size = size;
        this.arr = new int[size];
    }
    void input(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the elements of the array: ");
        for(int i = 0; i < size; i++){
            arr[i] = sc.nextInt();
        }
    }
    void display(){
        for(int i = 0; i <size; i++){
            System.out.print(arr[i] + "\t");
        }
        System.out.println();
    }
    void bubblesort(){
        for(int i = size-1;i>0;i--){
            for(int j = 0; j < i; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

class BubbleSort{
    public static void main(String args[]){
        Scanner xy = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size = xy.nextInt();
        Array new_arr = new Array(size);
        new_arr.input();
        new_arr.bubblesort();
        System.out.println("The sorted array is: ");
        new_arr.display();
    }
}

//sample output
/*
Enter the size of the array: 
10
Enter the elements of the array: 
14
5
56
4
11
2
3
86
1
-34
The sorted array is: 
-34     1       2       3       4       5       11      14      56      86
*/