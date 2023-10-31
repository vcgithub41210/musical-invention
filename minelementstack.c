#include <stdio.h>
#define MAX  5
int stack_arr[MAX];
int min_stack[MAX];
int min_top = -1;
int top =  -1;

int Push(int stack[],int min_stack[],int *min_top, int *pointer)
{
	int data;
	*pointer += 1;
	printf("Enter the element to be pushed: ");
	scanf("%d",&data);
	stack[*pointer] = data;
	printf("the element was successfully added to the top\n\n\n");
	if(*min_top == -1 || data < min_stack[*min_top])
	{
		*min_top += 1;
		min_stack[*min_top] = data;
	}
}

int Pop(int stack[],int min_stack[],int *min_top, int *pointer)
{
	printf("The popped element is: %d\n\n\n",stack[*pointer]);
	if(stack[*pointer] == min_stack[*min_top]) *min_top -= 1;
	*pointer -= 1;
}

int Peek(int stack[], int *pointer)
{
	printf("The minimum element is: %d\n\n\n",stack[*pointer]);
}

int main()
{
	int operand = 5;
	while(operand != 0){
		printf("Push elements into the stack until it is full:\nPush(1)\nPop(2)\nQuit(0)\n=>");
		scanf("%d",&operand);
		if(operand == 1){
			if(top == MAX-1)
			{
				printf("The stack is full!\n\n\n");
				break;
			}
			else Push(stack_arr,min_stack,&min_top,&top);
		}
		else if(operand == 2){
			if(top == -1) printf("impossible to pop(stack is empty)\n\n\n");
			else Pop(stack_arr,min_stack,&min_top,&top);
		}
	}
	if(min_top == -1) printf("the stack is empty so no minimum element!\n");
	else Peek(min_stack,&min_top);
}