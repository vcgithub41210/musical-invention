#include <stdio.h>

int Linear_Search(int *list,int size,int target)
{
	for(int i =0;i<size;i++)
	{
		if(list[i] == target) return printf("The element has been found at index: %d\n",i);
	}
	printf("The element was not found!");
}
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
	Linear_Search(list,size,target);
}
