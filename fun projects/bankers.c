#include <stdio.h>
#include <string.h>

//functions for input and display
int display(int size,int allocated[][3],int max[][3],int need[][3],int available[]){
  printf("\x1b[2J\x1b[HProcesses\tAllocated\tMax\tNeed\t\tAvailable\n");
  for(int i = 0; i < size;i++){
    printf("%d\t\t",i+1);
    for(int j = 0; j < 3; j++){
      if(allocated[i][j] < 0){
        printf("-  ");
      }
      else{
        printf("%d  ",allocated[i][j]);
      }
    }
    printf("\t");
    for(int j = 0; j < 3; j++){
      if(max[i][j] < 0){
        printf("- ");
      }
      else{
        printf("%d ",max[i][j]);
      }
    }
    printf("\t");
    for(int j = 0; j < 3; j++){
      if(need[i][j] < 0){
        printf("-  ");
      }
      else{
        printf("%d  ",need[i][j]);
      }
    } 
    printf("\t");
    if(i == 0){
      for(int j = 0; j < 3;j++){
        if(available[j] < 0){
          printf("-  ");
        }
        else{
          printf("%d  ",available[j]);
        }
      }
    }
    printf("\n");
  }
}
void allocated_resources_input(int size,int allocated[][3],int max[][3],int need[][3],int available[]){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < 3; j++){
      display(size,allocated,max,need,available);
      printf("Enter the allocated resources for process %d : ",i+1);
      scanf("%d",&allocated[i][j]);
    }
  } 
}
void resources_max_input(int size,int allocated[][3],int max[][3],int need[][3], int available[]){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < 3; j++){
      display(size,allocated,max,need,available);
      printf("Enter the max resource needs for process %d : ",i+1);
      scanf("%d",&max[i][j]);
      need[i][j] = max[i][j] - allocated[i][j];
    }
  }
}
void resources_available_input(int size,int allocated[][3],int max[][3],int need[][3],int available[]){
  for(int i = 0 ; i < 3; i++){
    display(size,allocated,max,need,available);
    printf("Enter the avaiable resources: ");
    scanf("%d",&available[i]);
  }
}

//function to check if the need of a process is satisfied by the available resources
int need_satisfied(int need[],int available[]){
  for (int i = 0; i < 3; i++){
    if(need[i] > available[i]){
      return 0;
    }
  }
  return 1;
}

//bankers algorithm function (MAIN PART)
void state_issafe(int size,int allocated[][3],int need[][3],int available[],int finish[]){
  printf("Process schedule: ");
  int flag = size;
  int index = 0;
  while(flag != 0){
    if(finish[index] != 1 && need_satisfied(need[index],available)){ // checking if the process is not finished and if the needs are satisfied
      flag = size;                      //flag set back to size (number of processes)
      finish[index] = 1;                //setting finish of (i+1)th process as true
      for(int i = 0; i < 3; i++){
        available[i] += allocated[index][i];   //adding the allocated resources back to available
      }
      printf("P%d\t",index+1);  //printing the schedule of the process along the way
    }
    else flag -= 1;            //flag value decremented, if flag becomes zero then exit the while loop                 
    index = (index + 1)%size;  //circular looping of processes
  }
}

//main
void main(){
  int size;
  printf("Enter the number of processes: ");
  scanf("%d",&size);


  //initializing array's
  int finish[size];
  memset(finish,0,sizeof(finish));    //setting all values as 0... 0 means the process is not finished executing and 1 means finished
  int available[3];
  int allocated[size][3],max[size][3],need[size][3];
  memset(allocated,-1,sizeof(allocated));    //setting all values as -1, indicating null values
  memset(max,-1,sizeof(max));                //setting all values as -1
  memset(need,-1,sizeof(need));              //setting all values as -1
  memset(available,-1,sizeof(available));    //settings all values as -1


  //input resources
  allocated_resources_input(size,allocated,max,need,available);
  resources_max_input(size,allocated,max,need,available);
  resources_available_input(size,allocated,max,need,available);
  display(size,allocated,max,need,available);


  //performing the safe algorithm
  state_issafe(size,allocated,need,available,finish);
  for(int i = 0; i < size;i ++){
    if (finish[i] != 1){                               //to check if any process is unfinished
      printf("\nThe system is not in safe state ");
      return;
    }
  }
  printf("\nThe system is in safe state\n");    //if all processes are finished
}
