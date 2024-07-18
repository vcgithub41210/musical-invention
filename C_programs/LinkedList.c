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
    Node *ptr = head;
    while(ptr != NULL)
    {
        if(ptr->data == value){
            printf("Enter the data of the new node: ");
            scanf("%d",&new_node->data);
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
    if(head->data == value){
        printf("Enter the data of the new node: ");
        scanf("%d",&new_node->data);
        new_node->next = head;
        head = new_node;
        return;
    }
    Node *ptr = head;
    while(ptr->next != NULL)
    {
        if(ptr->next->data == value){
            printf("Enter the data of the new node: ");
            scanf("%d",&new_node->data);
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
    if(position == 1){
        printf("Enter the data of the new node: ");
        scanf("%d",&new_node->data);
        new_node->next = head;
        head = new_node;
        return;
    }
    Node *ptr = head;
    int count = 1;
    while(ptr != NULL){
        if(count == position-1 && ptr->next != NULL){
            printf("Enter the data of the new node: ");
            scanf("%d",&new_node->data);
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        count++;
        ptr = ptr->next;
    }
    printf("Positon out of range\n");
}

void DeleteNode(){
    printf("Enter the data of the node to be deleted: ");
    scanf("%d",&value);
    if(head->data == value) head = head->next;
    else{
        Node *ptr = head;
        while(ptr->next != NULL){
            if(ptr->next->data == value){
                ptr->next = ptr->next->next;
                return;
            }
            ptr = ptr->next;
        }
        printf("Node does not exist\n");
    }
}

void DeleteAtPos(){
    printf("Enter the position of the node to be deleted (head has position 1)");
    scanf("%d",&position);
    if(position == 1) head = head->next;
    else{
        Node *ptr = head;
        int count = 1;
        while(ptr->next != NULL){
            if(count == position-1){
                ptr->next = ptr->next->next;
                return;
            }
            count++;
            ptr = ptr->next;
        }
        printf("Position out of range\n");
    }
}

void DeleteSmallestNode(){
    int min = head->data;
    Node *minptr = head;
    Node *ptr = head;
    if(head->next == NULL){
        head = head->next;
        return;
    }
    while(ptr->next != NULL){
        if(ptr->next->data < min){
            min = ptr->next->data;
            minptr = ptr;
        }
        ptr = ptr->next;
    }
    if(min == head->data)head = head->next;
    else{
        minptr->next = minptr->next->next;
    }
}

void SearchNode(){
    printf("Enter the data of the node to be searched: ");
    scanf("%d",&value);
    Node *ptr = head;
    position = 1;
    while(ptr != NULL){
        if(ptr->data == value){
            printf("The node is present at: %d\n",position);
            return;
        }
        ptr = ptr->next;
        position++;
    }
    printf("Node not found\n");
}

void Display(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    Node *ptr = head;
    while(ptr != NULL){
        printf("[%d]->",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    int operand;
    printf("(1)AddEnd\t(2)AddAfter\t(3)AddBefore\n(4)AddAtPosition\t(5)DeleteNode\t(6)DeleteAtPosition\n(7)DeleteSmallestNode\t(8)SearchForNode\t(9)Quit\n");
    while(operand != 9){
        printf("=> ");
        scanf("%d",&operand);
        if(operand == 1) AddEnd();
        else if(head == NULL) printf("list is empty\n");
        else{
            switch(operand){
                case 2:
                    AddAfter();
                    break;
                case 3:
                    AddBefore();
                    break;
                case 4:
                    AddAtPos();
                    break;
                case 5:
                    DeleteNode();
                    break;
                case 6:
                    DeleteAtPos();
                    break;
                case 7:
                    DeleteSmallestNode();
                    break;
                case 8:
                    SearchNode();
                    break;
                case 9:
                    continue;
                default:
                    printf("Invalid operand\n");
            }
        }
        Display();
    }
}
