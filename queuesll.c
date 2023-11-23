#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Node;
Node *front = NULL;
Node *rear = NULL;

void Enqueue(){
	Node *new_node = (Node*)malloc(sizeof(Node));
	printf("Enter the data of the new node: ");
	scanf("%d",&new_node->data);
	if(front == NULL){
		front = new_node;
	}
	else rear->next = new_node;
	rear = new_node;
}

void Dequeue(){
	if(front == NULL){
		printf("The queue is empty!\n");
		return;
	}
	Node *temp = front;
	if(front == rear) rear = rear->next;
	front = front->next;
	printf("The data of the dequeued node is: %d\n",temp->data);
	free(temp);
}

void Display(){
	Node *ptr = front;
	while(ptr != NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(){
	int operand;
	printf("Enter the operation;\n");
	printf("(1)Enqueue\t(2)Dequeue\t(3)Quit\n");
	while(operand != 3){
		printf("=> ");
		scanf("%d",&operand);
		switch(operand){
			case 1:
				Enqueue();
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				continue;
			default:
				printf("Invalid operation!\n");
		}
		if(front != NULL)Display();
	}
}
