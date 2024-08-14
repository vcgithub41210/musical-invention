#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(){
}
void LFU(){
}
void LRU(){
}
void FCFS(){
}
int main(){
  int num_pages;
  printf("Enter the number of pages: ");
  scanf("%d",&num_pages);
  char *page_sequence = (char*)malloc(num_pages*sizeof(char));
  printf("Enter the page sequence: ");
  scanf("%s",page_sequence);
  printf("The page sequence is %s",page_sequence);
}
