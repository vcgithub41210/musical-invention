#include <stdio.h>
#define MAX  5
int stack_arr[MAX];
int top =  -1;

int Push(int stack[], int *pointer)
{
	*pointer += 1;
	printf("Enter the element to be pushed: ");
	scanf("%d",&stack[*pointer]);
	printf("the element was successfully added to the top\n\n\n"); 
}
int Pop(int stack[], int *pointer)
{
	printf("The popped element is: %d\n\n\n",stack[*pointer]);
	*pointer -= 1;
}
int Peek(int stack[], int *pointer)
{
	printf("The top element is: %d\n\n\n",stack[*pointer]);
}

int main()
{
	int operand = 5;
	while(operand != 0){
		printf("What operation do you want to perform:\nPush element to the top(1)\nPop the top element(2)\nPeek the top element(3)\nQuit(0)\n=>");
		scanf("%d",&operand);
		if(operand == 1){
			if(top == MAX-1) printf("stack overflow, cannot add element\n\n\n");
			else Push(stack_arr,&top);
		}
		else if(operand == 2){
			if(top == -1) printf("impossible to pop(stack is empty)\n\n\n");
			else Pop(stack_arr,&top);
		}
		else if(operand == 3){
			if(top == -1) printf("the stack is empty!\n\n\n");
			else Peek(stack_arr,&top);
		}
	}
}