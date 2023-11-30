import java.io.*;
import java.util.Scanner;

class List{
    int size;
    int arr[] = new int[100];
    void sort(){
        for(int i = 1;i < size; i++)
        {
            int temp = arr[i];
            int j = i-1;
            while(j>= 0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }

    void search(int target){
        int start = 0;
        int end = size;
        while(start <= end){
            int middle = (start+end)/2;
            if(arr[middle] == target){
                System.out.println("The element is found at index: "+ middle);
                return;
            }
            else if(arr[middle] > target) end = middle-1;
            else start = middle+1;
        }
        System.out.println("The element is not found!");
    }
    
    void input(){
        Scanner xy = new Scanner(System.in);
        System.out.println("Enter the number of elements of the array: ");
        size = xy.nextInt();
        System.out.println("Enter the elements of the array:\n");
        for(int i = 0; i < size; i++)
        {
            int value = xy.nextInt();
            arr[i] = value;
        }
    }

    void Display(){
        for(int i = 0; i < size; i++){
            System.out.print(arr[i] + "\t");
        }
    }
}

class Binary{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        List binarr = new List();
        binarr.input();
        binarr.sort();
        binarr.Display();
        System.out.println("\nEnter the element to be searched: ");
        int target = sc.nextInt();
        binarr.search(target);
    }
}

//output
/*
Enter the number of elements of the array: 
10
Enter the elements of the array:

89
3
74
70
8
-100
23
13
56
66
-100    3       8       13      23      56      66      70      74      89
Enter the element to be searched: 
74
The element is found at index: 8
*/