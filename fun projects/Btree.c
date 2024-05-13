#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int array[5];
  struct node *pointer;
}

int main(){
  int operation;
  while(operation != 0){
    printf("Enter the operation you want to perform;\n1) Insert\n2) Delete\n3) Search\n0) Quit\n");
    scanf("%d",&operation);
    switch(operation){
case 0:
    continue;
case 1:
    printf("The insert function has been called\n");
    break;
case 2:
    printf("The delete function has been called\n");
    break;
case 3:
    printf("The search function has been called\n");
    break;
default:
    printf("Invalid operation! Try again\n");
    break;
    }
  }
