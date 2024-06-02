#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

sem_t semaphore;

void display(int* array,int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(*(array+(i*size)+j) == 0)
        printf("-\t");
      else
        printf("%d\t",*(array+(i*size)+j));
    }
    printf("\n");
  }
  printf("\n");
}

void* display_thread(void* args){
  int **inptr = (int **)args;
  int *matrix = *(inptr+1);
  for(int i=0; i< **inptr;i++){
    for(int j=0; j< **inptr;j++){
      printf("%d\t",*(matrix+(i*(**inptr))+j));
    }
    printf("\n");
  }
}

void* DETERMINANT(void* args){
  int **ptr = (int**)args;
  int *size = *(ptr);
  int *matrix = *(ptr+1);
  int *excluded = (int*)malloc((*size)*sizeof(int));
  memcpy(excluded,*(ptr+2),(*size)*sizeof(int));
  int row_number = *(*(ptr+3));
  int *multiplier = *(ptr+4);
  int *result = *(ptr+5);

  if(row_number != *size){
    pthread_t *jointhread = (pthread_t*)malloc((*size)*sizeof(pthread_t*));
    int new_result = 0;
    int count = 0;
    for(int i = 0; i < *size;i++){
      if(*(excluded+i) != 1){
        //generating new inputs
        int *new_excluded = (int*)malloc((*size)*sizeof(int));
        memcpy(new_excluded,excluded,(*size)*sizeof(int));
        *(new_excluded + i) = 1;
        int *new_row_number = (int*)malloc(sizeof(int));
        *new_row_number = row_number+1;
        int *new_multiplier = (int*)malloc(sizeof(int));
        *new_multiplier = *(matrix+row_number+(i*(*size)));
        if(count % 2 == 1){
          *new_multiplier = -(*new_multiplier);
        }
        //new arguement creater
        int **new_ptr = (int**)malloc(8*sizeof(int*));
        memcpy(new_ptr,ptr,8*sizeof(int*));
        //adding values 
        *(new_ptr+2) = new_excluded;
        *(new_ptr+3) = new_row_number;
        *(new_ptr+4) = new_multiplier;
        *(new_ptr+5) = &new_result;
        //

        //generating pthreads for each outcome
        pthread_t thread = (pthread_t)malloc(sizeof(pthread_t));
        pthread_create(&thread,NULL,DETERMINANT,new_ptr); 
        *(jointhread+i) = thread;
        count++;
      }
    }
    for(int i = 0;i< *size;i++){
      if(*(excluded+i) != 1){
        pthread_join(*(jointhread+i),NULL);
      }
    }
    *result += (*multiplier * (new_result));
  }
  else{
    *result += *multiplier;
  }
}


int main(){
  //MATRIX INPUt
  int size;
  printf("Enter the size of the square matrix(maximum size: 16x16) ==> ");
  scanf("%d",&size);
  int *square_matrix = (int*)malloc(size*size*sizeof(int));
  for(int i = 0 ; i < size*size; i ++){
    printf("\x1b[2J\x1b[H\n");
    display(square_matrix,size);
    printf("Enter the next element: ");
    scanf("%d",(square_matrix+i));
  }
    printf("\x1b[2J\x1b[H\n");
    display(square_matrix,size);
  //END


  //INTEGER POINTER ARRAY INITIALIZATION
  int **input = (int **)malloc(6*sizeof(int*));

  //integer pointer requirements intialization
  int *excluded_rows_arr = (int*)malloc(size*sizeof(int));
  int row_number = 0;
  int multiplier = 1;
  int result = 0;

  //integer pointer array pointers
  *(input) = &size;
  *(input+1) = square_matrix;
  *(input+2) = excluded_rows_arr;
  *(input+3) = &row_number;
  *(input+4) = &multiplier;
  *(input+5) = &result;


  pthread_t MAINTHREAD;
  pthread_create(&MAINTHREAD,NULL,DETERMINANT,input);
  pthread_join(MAINTHREAD,NULL);

  printf("\n\n\nThe determinant of the matrix is ==> %ld\n\n\n",result);
}
