#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t semaphore;
//structure
typedef struct dt{
  int number;
  int remainder;
  int index;
}dt;

void* number_division(void* args){
  dt* temp = (dt*)args;
  while(temp->number != 0){
    sem_wait(&semaphore);
    if(temp->remainder == -1){
    temp->remainder = temp->number % 16;
    printf("thread 1 generated a remainder : %d from the number : %d\n",temp->remainder,temp->number);
    temp->number = temp->number / 16;
    }
    sem_post(&semaphore);
    sleep(4);
  }
  int* ptr = (int*)malloc(sizeof(int));
  *ptr = temp->index;
  return ptr;
}

void* remainder_tohex(void* args){
  char* output = (char*)malloc(100*sizeof(char));
  dt* temp = (dt*)args;
  temp->index = 0;
  while(temp->number != 0 || temp->remainder != -1){
    sem_wait(&semaphore);
    if (temp->remainder != -1){
    if(temp->remainder > 9){
      output[temp->index] = (char)(65 + (temp->remainder % 10));
    }
    else{
      output[temp->index] = (char)(48 + temp->remainder);
    }
    printf("thread2 generated a hex conversion of %d ::: %c\n",temp->remainder,output[temp->index]);
    temp->index++;
    temp->remainder = -1;
    }
    sem_post(&semaphore);
    sleep(4);
  }
  output[temp->index] = '\0';
  return output;
}

int main(){
  char* output;
  int* index;
  dt* temp = (dt*)malloc(sizeof(dt));
  temp->remainder = -1;
  sem_init(&semaphore,0,1);
  scanf("%d",&temp->number);
  int number = temp->number;

  pthread_t thread1;
  pthread_t thread2;
  pthread_create(&thread1,NULL,number_division,temp);
  pthread_create(&thread2,NULL,remainder_tohex,temp);

  pthread_join(thread1,(void *)&index);
  pthread_join(thread2,(void *)&output);
  printf("The hexadecimal conversion is: ");
  for(int i = temp->index - 1; i >= 0;i--){
    printf("%c",output[i]);
  }
  printf("\n");
}
