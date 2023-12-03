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
    void quicksort(){
        for(int i = 1; i<size;i++){
            int temp = arr[i];
            int j = i-1;
            while(j>=0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }
}

class QuickSort{
    public static void main(String args[]){
        Scanner xy = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int size = xy.nextInt();
        Array new_arr = new Array(size);
        new_arr.input();
        new_arr.quicksort();
        System.out.println("The sorted array is: ");
        new_arr.display();
    }
}

//sample output
/*
Enter the size of the array: 
5
Enter the elements of the array: 
9
1
78
-10
3
The sorted array is: 
-10     1       3       9       78
*/