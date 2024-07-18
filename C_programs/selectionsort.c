#include <stdio.h>

int Display(int *list,int size)
{
	for(int i = 0; i< size; i++)
	{
		printf("%d\t",list[i]);
	}
	printf("\n");
}

int Selection_Sort(int *list,int size)
{
	int temp;
	for(int i = 0; i<size-1;i++)
	{
		int min = i;
		for(int j = i+1;j<size;j++)
		{
			if(list[j] < list[min]) min = j;
		}
		temp = list[min];
		list[min] = list[i];
		list[i] = temp;
		Display(list,size);
	}
}
int main()
{
	int size;
	printf("Enter the number of elements of the array: ");
	scanf("%d",&size);
	int list[size];
	printf("Enter the elements of the array:\n");
	for(int i = 0;i<size;i++)
	{
		scanf("%d",&list[i]);
	}
	Selection_Sort(list,size);
	printf("***Final Sorted Array***\n");
	Display(list,size);
}
