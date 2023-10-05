#include <stdio.h>

int Display(int *list, int size)
{
	for(int i = 0 ; i < size; i++)
	{
		printf("%d\t",list[i]);
	}
	printf("\n");
}

int Bubble_Sort(int *list,int size)
{
	int temp;
	for(int i = size-1; i > 1; i--)
	{
		for(int j = 0; j < i;j++)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j+1];
				list[j+1] = list[j];
				list[j] = temp;
				Display(list,size);
			}
		}
	}
}


int main()
{
	int size;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	int list[size];
	printf("Enter the elements of the array:\n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d",&list[i]);
	}
	Bubble_Sort(list,size);
	printf("***Final Sorted List***\n");
	Display(list,size);
}
