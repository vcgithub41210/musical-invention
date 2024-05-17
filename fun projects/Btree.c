#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//our goal is to implement a btree in c language
// this involves operations like addition deletion and searching
// maybe display as well
// so hence we need atleast 3 functions
// on top of that we need to sort the array of items inside each node and hence we need a sorting function

typedef struct node{
  int length; // to keep track of length of the array
  int array[5]; //array of data
  struct node *pointer[6]; //array of pointers
} node;

node *root; //root node of the tree 
            // btree has an instruction which specifies that every node must have atmost 2 elements except the root

int binary_search(int data,int array[],int length){
  int start = 0;
  int end = length-1;
  int middle;
  while(start <= end){
    middle = (start+end)/2;
    if(array[middle] < data)
      start = middle+1;
    else
      end = middle-1;
  }
  return start;
}

int insert_into_node(node *nd,int data,int index,node *ptr){
  if(nd == root && nd->length == 0){
    nd->array[0] = data;
  }
  else{
    for(int i = nd->length; i > index; i--){
      nd->array[i] = nd->array[i-1];
      if(nd->pointer[i])nd->pointer[i+1] = nd->pointer[i];
    }
    nd->pointer[index+1] = nd->pointer[index];
    nd->array[index] = data;
    nd->pointer[index] = ptr;
  }
  nd->length++;
}
void transfer_data(node *temp,node *nd,int start,int end){
  int j = 0;
  for(int i = start;i < end;i++){
    temp->array[j] = nd->array[i];
    if(nd->pointer[j])temp->pointer[j] = nd->pointer[j];
    j++;
  }
  temp->pointer[j] = nd->pointer[j];
  temp->length = 2;
}
node *split_node(node *nd){
  node *tmp1 = (node*)malloc(sizeof(node));
  transfer_data(tmp1,nd,0,2);
  node *tmp2 = (node*)malloc(sizeof(node));
  transfer_data(tmp2,nd,3,5); 
  node *tmp = (node*)malloc(sizeof(node));
  tmp->array[0] = nd->array[2];
  tmp->pointer[0] = tmp1;
  tmp->pointer[1] = tmp2;
  tmp->length = 1;
  return tmp;
}
node *traverse_node(node *nd,int data){
  int length = nd->length;
  if (length == 0){
    insert_into_node(nd,data,0,NULL);
  }
  else{
    node *temp;
    int index = binary_search(data,nd->array,length); //to find the correct pointer where 
    for(int i = 0 ; i < nd->length; i++){
      printf("%d\t",nd->array[i]);
    }
    printf("\nindex: %d\n\n",index);
    if(nd->pointer[index] != NULL){
      temp = traverse_node(nd->pointer[index],data);
      if(temp != nd->pointer[index]){
        nd->pointer[index] = temp->pointer[1];
        insert_into_node(nd,temp->array[0],index,temp->pointer[0]);
      }
      else return nd;
    }
    else{
      insert_into_node(nd,data,index,NULL);

    }
    if(nd->length == 5) return split_node(nd);
    else return nd;
  }
}
void display(node *nd, int level) {
  if (nd != NULL) {
    printf("Level %d [", level);
    for (int i = 0; i < nd->length; i++) {
      printf(" %d", nd->array[i]);
    }
    printf(" ]\n");
    for (int i = 0; i <= nd->length; i++) {
      display(nd->pointer[i], level + 1);
    }
  }
}
int main(){
  root = (node*)malloc(sizeof(node));
  int operation;
  while(operation != 0){
    printf("Enter the operation you want to perform;\n1) Insert\n2)Delete\n3)Search\n0)Quit");
    scanf("%d",&operation);
    int data;
    switch(operation){
      case 0:
        continue;
      case 1:
        if(root->length < 5){
          printf("Enter the data: ");
          scanf("%d",&data);
          root = traverse_node(root,data);
        }
        else
          printf("Root is full\n");
        break;
      case 2:
        // the deletzae function called
        printf("the delete function has been called\n");
        break;
      case 3:
        //search functzaion called
        printf("the search function has been called\n");
        break;
      default:
        printf("invalid operation! try again\n");
        break;
    }
    if (root != NULL) {
      display(root, 0);
    }
    printf("\n");

  }
}
