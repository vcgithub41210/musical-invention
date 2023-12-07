#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node node;
node *root = NULL;
node **queue;
int start = -1;
int rear = -1;

void enqueue(node *temp){
    if(start == -1) start++;
    queue[++rear] = temp;
}
node *dequeue(){
    node *temp = queue[start];
    if(start == rear) start = rear = -1;
    else start++;
    return temp;
}
node *createNode(int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    return new_node;
}

void insert(int data){
    node *new_node = createNode(data);
    if(root == NULL){
        root = new_node;
        return;
    }
    node *ptr = root;
    node *prev = NULL;
    while(ptr != NULL){
        prev = ptr;
        if(ptr->data <= new_node->data){
            ptr = ptr->right;
            continue;
        }
        else{
            ptr = ptr->left;
            continue;
        }
    }
    if(prev->data <= new_node->data){
        prev->right = new_node;
    }
    else{
        prev->left = new_node;
    }
}


void levelorder(){
    enqueue(root);
    while(rear != -1){
        node *temp = dequeue();
        printf("%d ",temp->data);
        if(temp->left != NULL) enqueue(temp->left);
        if(temp->right != NULL) enqueue(temp->right);
    }
}


// void printSpaces(int n) {
//     for (int i = 0; i < n; ++i)
//         printf(" ");
// }
// // Function to print the BST in an aesthetic way
// void printBST(node *root, int space) {
//     if (root == NULL)
//         return;

//     // Increase distance between levels
//     space += 5;

//     // Process right child first
//     printBST(root->right, space);

//     // Print current node after space
//     printf("\n");
//     printSpaces(space);
//     printf("%d\n", root->data);

//     // Process left child
//     printBST(root->left, space);
// }

int main(){
    int N,data;
    printf("Enter the number of nodes of the tree: ");
    scanf("%d",&N);
    queue = (node**)malloc(N *sizeof(node));
    printf("Enter the data of the nodes of the tree:\n");
    for(int i = 0; i < N; i++){
        scanf("%d",&data);
        insert(data);
    }
    levelorder();
    // printBST(root,0);
}