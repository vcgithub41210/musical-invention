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
  struct node *pointer[5]; //array of pointers
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

//[1,3,7,12,14]
int insert_in_node(node *root){
  int data;
  int length = root->length;
  printf("Enter the data to be inserted: ");
  scanf("%d",&data);
  if (length == 0){
    root->array[0] = data;
    root->length++;
  }
  else{
    int index = binary_search(data,root->array,length); //to find the correct pointer where 
    for(int i = length; i > index;i--){
      root->array[i] = root->array[i-1];
    }
    root->array[index] = data;
    root->length++;
  }
}
int main(){
  root = (node*)malloc(sizeof(node));
  int operation;
  while(operation != 0){
    printf("Enter the operation you want to perform;\n1) Insert\n2)Delete\n3)Search\n0)Quit");
    scanf("%d",&operation);
    switch(operation){
      case 0:
        continue;
      case 1:
        if(root->length < 5){
          insert_in_node(root);
          printf("%d\n",root->length);
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
    if(root != NULL){
      for (int i = 0; i < root->length;i++){
        printf("%d\t",root->array[i]); 
      }
      printf("\n");
    }
    printf("\n");

  }
}
