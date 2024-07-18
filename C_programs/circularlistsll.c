#include <stdio.h>
#include <stdlib.h>


int operand;
int data;


struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *head = NULL;
node *rear = NULL;

node *CreateNode(int data){
	node *new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	return new_node;
}

void Insert(){
	printf("Enter the data of the new node: ");
	scanf("%d",&data);
	node *new_node = CreateNode(data);
	if(head == NULL){
		head = new_node;
		rear = new_node;
		rear->next = new_node;
		return;
	}
	rear->next = new_node;
	new_node->next = head;
	rear = new_node;
}

void Delete(){
	if(head == NULL){
		printf("List is empty!\n");
		return;
	}
	printf("Enter data of the node to be deleted: ");
	scanf("%d",&data);
	node *ptr = head;
	node *prev = NULL;
	while(ptr != head ||prev == NULL){
		if(ptr->data == data) break;
		prev = ptr;
		ptr = ptr->next;
	}
	node *temp;
	if(ptr == head){
		if(prev == NULL){
			temp = head;
			if(head->next == head){
				head = NULL;
				rear = NULL;
				return;
			}
			head = head->next;
			rear->next = head;
			return;
		}
		else{
			printf("Node does not exist!\n");
			return;
		}
	}
	else{
		temp = ptr;
		prev->next = ptr->next;
	}
	if(ptr == rear) rear = prev;
	free(temp);
}


void Display(){
	node *ptr = head;
	while(ptr->next != head){
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("%d->[%d...]\n\n",ptr->data,head->data);
}

int main(){
	printf("Enter the operation to perform:\n");
	printf("(1)Insert\n(2)Delete\n(3)Quit\n");
	do{
		printf("=> ");
		scanf("%d",&operand);
		switch(operand){
			case 1:
				Insert();
				break;
			case 2:
				Delete();
				break;
			case 3:
				continue;
			default:
				printf("Invalid operation!\n");
		}
		if(head != NULL) Display();
	}
	while(operand != 3);
}
