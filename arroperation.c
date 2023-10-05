#include <stdio.h>

//FUNCTION DEFINITION SECTION
//INSERT FUNCTION

int insert(int array[],int element,int position,int *size)
{
	for(int i = *size; i >= position; i--)
	{
		array[i+1] = array[i];
	}
	array[position] = element;
	*size += 1;
}

//DELETE FUNCTION

int deletion(int *array,int position,int *size)
{
	for(int i = position;i < *size; i++)
	{
		array[i] = array[i+1];
	}
	*size -= 1;
}

//SEARCH FUNCTION

int search(int *array,int element,int size)
{
	int i = 0;
	for (i; i< size; i++)
	{
		if(array[i] == element)
		{
			printf("The element has been found at index:%d",i);
			break;
		}
	}
	if(i == size)
	{
		printf("The element is not found!");
	}
}

//SORT FUNCTION

int sort(int *array,int size)
{
	int value;
	for(int i = size; i > 1; i--)
	{
		for(int j = 0; j < i;j++)
		{
			if(array[j]>array[j+1])
			{
				value = array[j+1];
				array[j+1] = array[j];
				array[j] = value;
			}
		}
	}
}

//DISPLAY FUNCTION

int display(int *array,int size)
{
	for(int i = 0; i< size;i++)
	{
		 printf("%d\t",array[i]);
	}
}

//MAIN FUNCTION

int main()
{
	/*array operations-
	searching element
	sorting elements*/
	int array[50],N,index,element;
	char operand;
	printf("Enter the elements of the array:");
	scanf("%d",&N);
	printf("Enter the elements of the array:\n");
	for(int i = 0;i < N; i++)
	{
		scanf("%d",&array[i]);
	}


	//menu
	printf("What operation would you like to perform on the array?\n");
	printf("1)insertion(i)\n2)deletion(d)\n3)searching(s)\n4)sorting(a)\n=> ");
	scanf("%s",&operand);


	//checking for operand
	switch(operand)
	{
		case 'i':
			printf("Enter the element to be inserted");
			scanf("%d",&element);
			printf("Enter the index position to be inserted at: ");
			scanf("%d",&index);
			insert(array,element,index,&N);
			display(array,N);
			break;
		case 'd':
			printf("Enter the index position whose element is to be deleted: ");
			scanf("%d",&index);
			deletion(array,index,&N);
			display(array, N);
			break;
		case 's':
			printf("Enter the element to be searched: ");
			scanf("%d",&element);
			search(array,element,N);
			break;
		case 'a':
			sort(array,N);
			display(array,N);
			break;
		case 'q':
			break;
	}
}
