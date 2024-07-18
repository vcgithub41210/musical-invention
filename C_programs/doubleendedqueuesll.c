#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};
typedef struct Node nd;
nd *front = NULL;
int data;

nd *createNode(int data){
	nd *new_node = (nd *)malloc(sizeof(nd));
	new_node->data = data;
	return new_node;
}

void AddFront(){
	printf("Enter the data of the new node: ");
	scanf("%d",&data);
	nd *new_node = createNode(data);
	if(front == NULL){
		front = new_node;
		return;
	}
	new_node->next = front;
	front = new_node;
}

void AddBack(){
	printf("Enter the data of the new node: ");
	scanf("%d",&data);
	nd *new_node = createNode(data);
	if(front == NULL){
		front = new_node;
		return;	
	}
	nd *ptr = front;
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = new_node;
}

void RemoveFront(){
	if(front == NULL){
		printf("Queue is empty!\n");
		return;
	}
	nd *temp = front;
	front = front->next;
	printf("The removed data is: %d\n",temp->data);
	free(temp);
}

void RemoveBack(){
	if(front == NULL){
		printf("Queue is empty!\n");
		return;
	}
	nd *ptr = front;
	nd *prev = NULL;
	while(ptr->next != NULL){
		prev = ptr;
		ptr = ptr->next;
	}
	nd *temp;
	if(ptr == front){
		temp = front;
		front = front->next;
	}
	else{
		temp = ptr;
		prev->next = ptr->next;
	}
	printf("The removed data is: %d\n",temp->data);
	free(temp);
}

void Display(){
	nd *ptr = front;
	while(ptr != NULL){
		printf("%d\t",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}


int main(){
	printf("Enter the operation you want to perform");
	printf("\n(1)Add at front\n(2)Add at back\n(3)Remove at front\n(4)Remove at back\n(5)Quit\n");
	int operand;
	do{
		printf("=> ");
		scanf("%d",&operand);
		switch(operand){
			case 5:
				continue;
			case 1:
				AddFront();
				break;
			case 2:
				AddBack();
				break;
			case 3:
				RemoveFront();
				break;
			case 4:
				RemoveBack();
				break;
			default:
				printf("Invalid operation!\n");
		}
		if(front != NULL) Display();
	}
	while(operand != 5);
}

//sample output
/**

Enter the operation you want to perform
(1)Add at front
(2)Add at back
(3)Remove at front
(4)Remove at back
(5)Quit
=> 3
Queue is empty!
=> 4
Queue is empty!
=> 1
Enter the data of the new node: 23
23	
=> 2
Enter the data of the new node: 14
23	14	
=> 2
Enter the data of the new node: 5
23	14	5	
=> 1
Enter the data of the new node: 67
67	23	14	5	
=> 4
The removed data is: 5
67	23	14	
=> 3
The removed data is: 67
23	14	
=> 4
The removed data is: 14
23	
=> 3
The removed data is: 23
=> 3
Queue is empty!
=> 5

*/
