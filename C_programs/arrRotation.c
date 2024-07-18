#include <stdio.h>

int Rotation(int *array,int size)
{
	int rotTime,direction,temp;
	printf("Enter the number of times to rotate: ");
	scanf("%d",&rotTime);
	printf("Enter the direction in which to rotate\nLeft(-1)\nRight(1)\n=> ");
	scanf("%d",&direction);
	if(direction == 1)
	{
		for(int i = 0; i < rotTime;i++)
		{
			temp = array[size-1];
			for(int j = size-1;j>=0;j--)
			{
				array[j+1] = array[j];
			}
			array[0] = temp;
		}
	}else if(direction == -1)
	{
		for(int i = 0; i < rotTime;i++)
		{
			temp = array[0];
			for(int j = 1;j <size;j++)
			{
				array[j-1] = array[j];
			}
			array[size-1] = temp;
		}
	}
	printf("\n\n");
	
}
int Display(int *array,int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%d\t",array[i]);
	}
	printf("\n");
}
int main()
{
	int size;
	char operand;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	int array[size];
	printf("Enter the elements of the array:\n");
	for(int i = 0; i < size; i++)
	{
		scanf("%d",&array[i]);
	}
	
	do
	{
		printf("Enter the operation to be done;\nRotation(r)\nDisplay(d)\nQuit(q)\n=> ");
		scanf("%c",&operand);
		
		switch(operand)
		{
			case 'r':
				Rotation(array,size);
				break;
			case 'd':
				Display(array,size);
				break;
			case 'q':
				break;
		}
	}
	while(operand != 'q');
	
}
