#include <stdio.h>

int Binary_Search(int *list,int start, int end, int size,int target)
{
	if(start <= end)
	{
		int middle = (start+end)/2;
		if(list[middle] == target) return printf("The element was found at index: %d",middle);
		else if(list[middle] < target) return Binary_Search(list,middle+1,end,size,target);
		else return Binary_Search(list,start,middle-1,size,target);
	}
	return printf("The element was not found!");
}
int main()
{
	int start = 0,end,size,target;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	int list[size];
	printf("Enter the elements of the array(sorted error):\n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d",&list[i]);
	}
	printf("Enter the element to be searched: ");
	scanf("%d",&target);
	end = size-1;
	Binary_Search(list,0,size-1,size,target);
}
