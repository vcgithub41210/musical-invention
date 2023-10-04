//A program to implement binary search

/*
Step 0- START
Step 1 - initialise start,end,middle,'list' array,size,target
Step 2 - input the size of the array as size
Step 3 - input the elements of the array in the sorted order
Step 4 - input the element to be searched as target
Step 5 - put start = 0 and end = size-1
Step 6 - while start < end, go to step 7, else go to step 12
Step 7 - put middle = (start+end)/2
Step 8 - if list[middle] == target then go to step 11,else go to step 9
Step 9 - else if list[middle] < target, put start = middle+1 and go to step 6, else go to step 10
Step 10 - else if list[middle] > target, put end = middle-1 and go to step 6
Step 11 - print the value of middle and go to step 13
Step 12 - print "the element is not found" and go to step 13 
Step 13 - STOP
*/

#include <stdio.h>

int main()
{
    int start = 0,end,middle,size,target;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int list[size];
    printf("Enter the elements of the array(sorted order):\n");
    for(int i = 0; i< size;i++)
    {
        scanf("%d",&list[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&target);
    end = size-1;
    while(start < end)
    {
        middle = (start+end)/2;
        if(list[middle] == target)
        {
            return printf("The element is found at index: %d",middle);
        }else if(list[middle] < target)
        {
            start = middle+1;
        }else{
            end = middle-1;
        }
    }
    return printf("The element was not found!");
}