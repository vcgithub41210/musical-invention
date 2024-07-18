#include <stdio.h>
#define MAX  5
int stack_arr[MAX];
int temp_arr[MAX];
int sorted_top = -1;
int top =  -1;

int Display(int stack[],int *pointer)
{
	printf("\nThe sorted stack is: [");
	if(*pointer != -1)
	{
		int i = 0;
		for(i; i < *pointer; i++)
		{
			printf("%d,",stack[i]);
		}
		printf("%d]\n",stack[i]);
	}
	else printf("]\n");
}

int Push(int stack[],int temp_arr[],int *sorted_top, int *pointer)
{
	int data;
	*pointer += 1;
	printf("Enter the element to be pushed: ");
	scanf("%d",&data);
	stack[*pointer] = data;
	printf("the element was successfully added to the top\n\n\n");
	*sorted_top += 1;
	temp_arr[*sorted_top] = data;
	int j = *sorted_top - 1;
	while(j>=0 && temp_arr[j] > data){
		temp_arr[j+1] = temp_arr[j];
		j--;
	}
	temp_arr[j+1] = data;
}
int Pop(int stack[],int temp_arr[],int *sorted_top, int *pointer)
{
	printf("The popped element is: %d\n\n\n",stack[*pointer]);
	int value = stack[*pointer];
	int index;
	for(int i = 0; i < *sorted_top+1;i++)
	{
		if(temp_arr[i] == value){
			index = i;
			break;
		}
	}
	
	for(int j = index+1;j < *sorted_top+1;j++)
	{
		temp_arr[j-1] = temp_arr[j];
	}
	*pointer -= 1;
	*sorted_top -= 1;
	printf("%d\n",*sorted_top);
}

int main()
{
	int operand = 5;
	while(operand != 0){
		printf("What operation do you want to perform:\nPush element to the top(1)\nPop the top element(2)\nQuit(0)\n=>");
		scanf("%d",&operand);
		if(operand == 1){
			if(top == MAX-1) printf("stack overflow, cannot add element\n\n\n");
			else Push(stack_arr,temp_arr,&sorted_top,&top);
		}
		else if(operand == 2){
			if(top == -1) printf("impossible to pop(stack is empty)\n\n\n");
			else Pop(stack_arr,temp_arr,&sorted_top,&top);
		}
		Display(temp_arr,&sorted_top); 
	}
}