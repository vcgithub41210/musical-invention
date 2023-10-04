//A program to perform linear search

/*
Algorithm:-
Step 0 - Start
Step 1 - initialise 'list' array, size, i = 0, target
Step 1 - input the number of elements of the array as size
Step 2 - input the elements of the array into the 'list' array
Step 3 - input the element to be searched as target
Step 4 - if i < size go to step 5, else go to step 7
Step 5 - if list[i] == target, go to step 6, else put i = i+1 and go to step 4
Step 6 - print the value of i and go to step 8
Step 7 - print "the element is not found" and go to step 8
Step 8 - STOP
*/

#include <stdio.h>

int main()
{
    int size,target;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int list[size];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&list[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&target);
    char bruh[50];
    for(int i = 0; i < size; i++)
    {
        if(list[i] == target)
        {
            return printf("The element has been found at index: %d",i);
        }
    }
    return printf("The element cannot be found!");
}