#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node Node;
Node *head = NULL;
int value;
int position;

void SortedAdd(){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = NULL;
    printf("Enter the data of the new node: ");
    scanf("%d",&new_node->data);
    if(head == NULL){
        head = new_node;
    }
    else{
        Node *ptr = head;
        while(ptr->next != NULL)
        {
            if(ptr->next->data > new_node->data){
            	new_node->next = ptr->next;
            	break;
            }
            ptr = ptr->next;
        }
        if(ptr == head){
        	if(head->data >= new_node->data){
        		new_node->next = head;
        		head = new_node;
        		return;
    		}
        }
        ptr->next = new_node;
    }
}

void ReverseList(){
	if(head == NULL){
		printf("list is empty\n");
		return;
	}
	Node *ptr = head;
	while(ptr->next != NULL) ptr = ptr->next;
	Node *new_head = ptr;
	while(head->next != NULL)
	{
		ptr = head;
		while(ptr->next->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next->next = ptr;
		ptr->next = NULL;
	}
	head = new_head;
}
void Display(){
    if (head == NULL){
    	printf("list is empty\n");
    	return;
    }
    Node *ptr = head;
    while(ptr != NULL)
    {
        printf("[%d]->",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}

int main(){
    int operand;
    printf("Choose the following: \n");
    printf("(1)SortedAdd\t(2)ReverseList\t(3)Display\t(4)Quit\n");
    while(operand != 4){
    	printf("=> ");
    	scanf("%d",&operand);
    	switch(operand){
    		case 1:
    			SortedAdd();
    			break;
    		case 2:
    			ReverseList();
    			break;
    		case 3:
    			Display();
    			break;
    		case 4:
    			continue;
    		default:
   			printf("Invalid operand\n");
    	}
    }
}
