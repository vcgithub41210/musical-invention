//A program to perform bubble sort

/*
Step 0 - START
Step 1 - initialise 'list' array, temp, i,j,size
Step 2 - input the size of the array as size
Step 3 - input the elements of the array
Step 4 - put i = size-1 and go to step 5
Step 5 - if i > 1, go to step 6 else go to step 10
Step 6 - put j = 0 and go to step 7
Step 7 - if j < i, go to step 8, else put i = i-1 and go to step 5
Step 8 - if list[j] > list[j+1], go to step 9, else put j=j+1 and go to step 7
Step 9 - put temp = list[j]
        put list[j] = list[j+1]
        put list[j+1] = temp
        put j = j+1 and go to step 7
Step 10 - STOP
*/

#include <stdio.h>

int main()
{
    int temp,size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int list[size];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size;i++)
    {
        scanf("%d",&list[i]);
    }
    for(int i = size-1;i>1;i--)
    {
        for(int j = 0;j < i;j++)
        {
            if(list[j] > list[j+1])
            {
                temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < size; i++)
    {
        printf("%d\t",list[i]);
    }
}