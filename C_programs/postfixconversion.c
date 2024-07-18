#include <stdio.h>
#include <string.h>
#define MAX 10

char stack_arr[MAX];
int top = -1;

int incoming_priority_checker(char symbol)
{
	switch(symbol){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '^':
			return 6;
		case '(':
			return 9;
		default:
			return 7;
	}
}

int stack_priority_checker(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
			return 2;
		case '*':
		case '/':
			return 4;
		case '^':
			return 5;
		case '(':
			return 0;
		default:
			return 8;
	}
}

void Push(char stack[],int *pointer,char symbol)
{
	*pointer += 1;
	stack[*pointer] = symbol;
}
char Pop(char stack[],int *pointer)
{
	char value = stack[*pointer];
	*pointer -= 1;
	return value;
}


void Conversion(char stack[],char expresssion[]){
	for(int i = 0; i < strlen(expresssion); i++)
	{
		char symbol = expresssion[i];
		if(symbol == ')')
		{
			while(stack[top] != '(' || top == -1)
			{
				char operator = Pop(stack,&top);
				printf("%c",operator);
			}
			Pop(stack,&top);

		}
		else if(top == -1)
		{
			int type = incoming_priority_checker(symbol);
			if(type == 7)
			{
				printf("%c",symbol);
			}
			else{
				Push(stack,&top,symbol);
			}
		}
		else{
			int priority1 = incoming_priority_checker(symbol);
			if(priority1 == 7)
			{
				printf("%c",symbol);
			}
			else
			{
				int priority2 = stack_priority_checker(stack[top]);
				while(priority2 >= priority1)
				{
					char operator = Pop(stack,&top);
					printf("%c",operator);
					priority2 = stack_priority_checker(stack[top]);
				}
				Push(stack,&top,symbol);
			}
		}
	}
	while(top != -1)
	{
		char operator = Pop(stack,&top);
		if(operator != '(')
		{
			printf("%c",operator);
		}
	}
}

int main()
{
	char expresssion[10];
	printf("Enter the infix expresssion: ");
	scanf("%s",&expresssion);
	Conversion(stack_arr,expresssion);
}