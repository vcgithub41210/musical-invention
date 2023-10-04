//A program to implement selection sort

/*
Step 0- START
Step 1- initialise 'list' array, size, min, temp, i,j
Step 2- input the number of elements of the array as size
Step 3- input the elements of the array
Step 4- put i = 0 and go to step 5
Step5 - if i < size-1, go to step 6, else go to step 11
Step 6- put min = i
        put j = i+1
Step 7 - if j < size, go to step 8, else go to step 10
Step 8 - if list[j] < list[min], put min = j and go to step 9, else go to step 9
Step 9 - put j=j+1 and go to step 7
Step 10 - put  temp = list[min];
            put list[min] = list[i]
            put list[i] = temp
            put i=i+1 and go to step 5
Step 11 - Print the array
Step 12 - STOP*/

#include <stdio.h>

int main()
{
    int size,min,temp;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&size);
    int list[size];
    printf("Enter the elements of the array:\n");
    for(int i = 0 ; i < size; i++)
    {
        scanf("%d",&list[i]);
    }
    for(int i = 0; i< size-1;i++)
    {
        min = i;
        for(int j = i+1;j < size; j++)
        {
            if(list[j] < list[min]) min = j;
        }
        temp = list[min];
        list[min] = list[i];
        list[i] = temp;
    }
    for(int i = 0;i<size;i++)
    {
        printf("%d\t",list[i]);
    }
}