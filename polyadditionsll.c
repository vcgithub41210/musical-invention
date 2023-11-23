#include <stdio.h>
#include <stdlib.h>

struct Node{
	int coeff;
	int pow;
	struct Node *next;
};
typedef struct Node Node;
Node *first = NULL;
Node *second = NULL;

void SortedAdd(Node **head,int coeff,int pow){
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->coeff = coeff;
	new_node->pow = pow;
	if(*head == NULL){
		*head = new_node;
		return;
	}
	if((*head)->pow < pow){
		new_node->next = *head;
		*head = new_node;
		return;
	}
	if((*head)->pow == pow){
		printf("term with the given power already exists!\n");
		return;
	}
	Node *ptr = *head;
	while(ptr->next != NULL){
		if(ptr->next->pow == pow){
			printf("term with the given power already exists!\n");
			return;
		}
		if(ptr->next->pow < pow){
			new_node->next = ptr->next;
			break;
		}
	}
	ptr->next = new_node;
}
void Input(Node **head){
	if(*head == first) printf("Enter the first polynomial;\n(0,0) => QUIT\n");
	else printf("Enter the second polynomial;\n(0,0) => QUIT\n");
	int coeff;
	int pow;
	do{
		printf("coeff=> ");
		scanf("%d",&coeff);
		printf("pow=> ");
		scanf("%d",&pow);
		//if(coeff != 0||pow != 0) printf("%d,%d",coeff,pow);
		if(coeff != 0||pow != 0) SortedAdd(head,coeff,pow);
		
	}
	while(coeff != 0 || pow != 0);
}
void Display(Node *head){
	if(head == NULL){
		printf("Empty Polynomial!\n");
		return;
	}
	while(head->next != NULL){
		printf("%d x^%d + ",head->coeff,head->pow);
		head = head->next;
	}
	printf("%d x^%d\n",head->coeff,head->pow);
}

int main(){
	Input(&first);
	Input(&second);
	Display(first);
}
