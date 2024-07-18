#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Node;
Node *top = NULL;

void Push(){
	Node *new_node = (Node*)malloc(sizeof(Node));
	printf("Enter the data of the new node: ");
	scanf("%d",&new_node->data);
	if(top != NULL){
		new_node->next = top;
	}
	top = new_node;
}
void Pop(){
	if(top == NULL){
		printf("Stack is empty!\n");
		return;
	}
	Node *temp = top;
	top = top->next;
	printf("The poped node has the data: %d\n",temp->data);
	free(temp);
}
void Peek(){
	if(top == NULL){
		printf("Stack is empty!\n");
		return;
	}
	printf("The top element is: %d\n",top->data);
}
void Display(){
	if(top == NULL){
		printf("Stack is empty!\n");
		return;
	}
	Node *ptr = top;
	while(ptr != NULL){
		printf("[%d]\n",ptr->data);
		ptr = ptr->next;
	}
}
int main(){
	int operand;
	printf("Enter the operation to perform;\n");
	printf("(1)Push\t(2)Pop\t(3)Peek\t(4)Quit\n");
	while(operand != 4){
		printf("=> ");
		scanf("%d",&operand);
		switch(operand){
			case 1:
				Push();
				break;
			case 2:
				Pop();
				break;
			case 3:
				Peek();
				break;
			case 4:
				continue;
			default:
				printf("Invalid operand!\n");
		}
		if(top != NULL) Display();
	}
}
