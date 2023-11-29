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
Node *result = NULL;
Node *result_rear = NULL;

Node *CreateNode(int coeff,int power){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->coeff = coeff;
    new_node->pow = power;
    new_node->next = NULL;
    return new_node;
}
void PolyAdd(Node *first,Node *second){
    while(first && second){
        Node *new_node;
        if(first->pow > second->pow){
            new_node = CreateNode(first->coeff,first->pow);
            first = first->next;
        }
        else if(first->pow < second->pow){
            new_node = CreateNode(second->coeff,second->pow);
            second = second->next;
        }
        else{
            new_node = CreateNode(first->coeff + second->coeff,first->pow);
            first = first->next;
            second = second->next;
        }
        if(result == NULL){
            result = new_node;
            result_rear = new_node;
        }
        else{
            result_rear->next = new_node;
            result_rear = new_node;
        }
    }
    while(first || second){
        Node *new_node;
        if(first){
            new_node = CreateNode(first->coeff,first->pow);
            first = first->next;
        }
        else if(second){
            new_node = CreateNode(second->coeff,second->pow);
            second = second->next;
        }
        if(result == NULL){
            result = new_node;
            result_rear = new_node;
        }
        else {
            result_rear->next = new_node;
            result_rear = new_node;
        }
    }
}

void SortedAdd(Node **head, int coeff, int pow) {
    Node *new_node = CreateNode(coeff,pow);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *prev = NULL;
    Node *current = *head;

    while (current != NULL && current->pow > pow) {
        prev = current;
        current = current->next;
    }

    if (current != NULL && current->pow == pow) {
        printf("Term with the given power already exists!\n");
        free(new_node); // Free the allocated memory for new_node
        return;
    }

    if (prev == NULL) {
        new_node->next = *head;
        *head = new_node;
    } else {
        prev->next = new_node;
        new_node->next = current;
    }
}

void Input(Node **head){
    if(*head == first) printf("***FIRST POLYNOMIAL***\n");
    else printf("***SECOND POLYNOMIAL***\n");
	int coeff;
	int pow;
    int operand;
	do{
        printf("Would you like to add another term? (1)Yes \t(2)No\n");
        scanf("%d",&operand);
        if(operand == 2){
            continue;
        }
		printf("coeff=> ");
		scanf("%d",&coeff);
		printf("pow=> ");
		scanf("%d",&pow);
		//if(coeff != 0||pow != 0) printf("%d,%d",coeff,pow);
		if (operand == 1 && (coeff != 0 || pow != 0)) {
            SortedAdd(head, coeff, pow);
        }
	}
	while(operand != 2);
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
	if(head->pow == 0) printf("%d\n",head->coeff,head->pow);
    else printf("%d x^%d\n",head->coeff,head->pow);
}

int main(){
	Input(&first);
	Input(&second);
    printf("***First Polynomial***\n");
	Display(first);
    printf("***Second Polynomial***\n");
    Display(second);
    printf("Adding two polynomials...\n");
    PolyAdd(first,second);
    printf("\n\n***Resultant Polynomial***\n");
    Display(result);
}

//Sample Output
/**
***FIRST POLYNOMIAL***
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 2
pow=> 5
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 6
pow=> 3
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 10
pow=> 1
Would you like to add another term? (1)Yes      (2)No
1
coeff=> -8
pow=> 2
Would you like to add another term? (1)Yes      (2)No
1
coeff=> -12
pow=> 0
Would you like to add another term? (1)Yes      (2)No
1
coeff=> -4
pow=> 4
Would you like to add another term? (1)Yes      (2)No
2
***SECOND POLYNOMIAL***
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 1
pow=> 4
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 2
pow=> 2
Would you like to add another term? (1)Yes      (2)No
1
coeff=> -3
pow=> 3
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 1
pow=> 0
Would you like to add another term? (1)Yes      (2)No
1
coeff=> -5
pow=> 1
Would you like to add another term? (1)Yes      (2)No
1
coeff=> 17
pow=> 2
Term with the given power already exists!
Would you like to add another term? (1)Yes      (2)No
2
***First Polynomial***
2 x^5 + -4 x^4 + 6 x^3 + -8 x^2 + 10 x^1 + -12
***Second Polynomial***
1 x^4 + -3 x^3 + 2 x^2 + -5 x^1 + 1
Adding two polynomials...


***Resultant Polynomial***
2 x^5 + -3 x^4 + 3 x^3 + -6 x^2 + 5 x^1 + -11
*/