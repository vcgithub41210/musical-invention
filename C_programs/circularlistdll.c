#include <stdio.h>
#include <stdlib.h>


int operand;
int data;


struct node{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node node;
node *head = NULL;

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
		head->next = head;
		head->prev = head;
		return;
	}
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
}

void Delete(){
	if(head == NULL){
		printf("List is empty!\n");
		return;
	}
	printf("Enter data of the node to be deleted: ");
	scanf("%d",&data);
	node *temp;
	if(head->data == data){
		if(head->next == head){
			temp = head;
			head = NULL;
			free(temp);
			return;
		}
		head->prev->next = head->next;
		head->next->prev = head->prev;
		temp = head;
		head = head->next;
		free(temp);
		return;
	}
	node *ptr = head->next;
	while(ptr != head){
		if(ptr->data == data) break;
		ptr = ptr->next;
	}
	if(ptr == head){
		printf("Node does not exist!\n");
		return;
	}
	else{
		temp = ptr;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(temp);
	}
}


void Display(){
	node *ptr = head;
	printf("[...%d] <--> ",head->prev->data);
	while(ptr->next != head){
		printf("%d <--> ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d <--> [%d...]\n\n",ptr->data,head->data);
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

//sample output
/**
Enter the operation to perform:
(1)Insert
(2)Delete
(3)Quit
=> 2
List is empty!
=> 1
Enter the data of the new node: 20
[...20] <--> 20 <--> [20...]

=> 1
Enter the data of the new node: 40
[...40] <--> 20 <--> 40 <--> [20...]

=> 1
Enter the data of the new node: 60
[...60] <--> 20 <--> 40 <--> 60 <--> [20...]

=> 1
Enter the data of the new node: 80
[...80] <--> 20 <--> 40 <--> 60 <--> 80 <--> [20...]

=> 1
Enter the data of the new node: 100
[...100] <--> 20 <--> 40 <--> 60 <--> 80 <--> 100 <--> [20...]

=> 2
Enter data of the node to be deleted: 120
Node does not exist!
[...100] <--> 20 <--> 40 <--> 60 <--> 80 <--> 100 <--> [20...]

=> 2
Enter data of the node to be deleted: 60
[...100] <--> 20 <--> 40 <--> 80 <--> 100 <--> [20...]

=> 2
Enter data of the node to be deleted: 20
[...100] <--> 40 <--> 80 <--> 100 <--> [40...]

=> 2
Enter data of the node to be deleted: 100
[...80] <--> 40 <--> 80 <--> [40...]

=> 2
Enter data of the node to be deleted: 80
[...40] <--> 40 <--> [40...]

=> 2
Enter data of the node to be deleted: 40
=> 2
List is empty!
=> 3
*/
