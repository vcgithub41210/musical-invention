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

void AddEnd(){
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
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void AddAfter(){
    Node *new_node = (Node *)malloc(sizeof(Node));
    printf("Enter the data of the reference node: ");
    scanf("%d",&value);
    printf("Enter the data of the new node: ");
    scanf("%d",&new_node->data);
    Node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == value){
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    }
    printf("Node does not exist\n");
}

void AddBefore(){
    Node *new_node = (Node *)malloc(sizeof(Node));
    printf("Enter the data of the reference node: ");
    scanf("%d",&value);
    printf("Enter the data of the new node: ");
    scanf("%d",&new_node->data);
    Node *ptr = head;
    if(head->data == value){
        new_node->next = head;
        head = new_node;
        return;
    }
    while(ptr->next != NULL)
    {
        if(ptr->next->data == value){
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    }
    printf("Node does not exist\n");
}

void AddAtPos(){
    Node *new_node = (Node*)malloc(sizeof(Node));
    printf("Enter the position at which node is to be added: ");
    scanf("%d",&position);
    printf("Enter the data of the new node: ");
    scanf("%d",&new_node->data);
    Node *ptr = head;
    int count = 1;
    if(position == 1){
        new_node->next = head;
        head = new_node;
        return;
    }
    while(ptr != NULL){
        if(count == position-1){
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        count++;
        ptr = ptr->next;
    }
    printf("Positon out of range\n");
}



void Display(){
    Node *ptr = head;
    while(ptr != NULL)
    {
        printf("[%d]->",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}
int main(){
    AddEnd();
    Display();
    AddAfter();
    Display();
    AddBefore();
    Display();
    AddAtPos();
    Display();
//     int operand;
//     printf("Choose the following:\n");
//     printf("(1)AddToEnd\n(2)AddAfterNode\n(3)AddBeforeNode\n(4)AddAtPosition\n(5)DeleteNode\n(6)DeleteAtPosition\n(7)DeleteSmallest\n(8)SearchData\n");
//     do{
//         printf("=> ");
//         scanf("%d",operand);
//         if (operand == 1){
//             AddEnd();
//         }
//         else if(head == NULL){
//             printf("list is empty!");
//         }
//         else{
//             switch(operand){
//                 case 2:
//                     AddAfter();
//                     break;
//             }
//         }
//         Display();
//     }while(operand != 0);
}