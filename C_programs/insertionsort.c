
#include <stdio.h>

int Display(int *list,int size)
{
	for(int i = 0; i< size; i++)
	{
		printf("%d\t",list[i]);
	}
	printf("\n");
}

int Insertion_Sort(int *list, int size)
{
	int temp;
	for(int i = 1;i < size;i++)
	{
		temp = list[i];
		int j = i-1;
		while(j>=0 && list[j] > temp)
		{
			list[j+1] = list[j];
			j--;
			Display(list,size);
		}
		list[j+1] = temp;
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
	Insertion_Sort(list,size);
	printf("***Final Sorted Array***\n");
	Display(list,size);
}
