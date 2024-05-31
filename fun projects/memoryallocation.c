#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_inputs(int memory_block_count,int process_count,int memory_blocks[],int processes[],int arr_target,int current_index,int flag_bit){
  int target = 0;
  int flag = flag_bit;
  printf("Memory Blocks:\t");
  for(int i = 0; i < memory_block_count; i++){
    if(flag != 1){
      if(i == current_index && target == arr_target){
        printf("\033[4m%d\033[0m\t",memory_blocks[i]);
        flag = 1;
      }
      else{
        printf("%d\t",memory_blocks[i]);
      }
    }
    else{
      printf("%d\t",memory_blocks[i]);
    }
  }
  target++;
  printf("\nProcess Size:\t");
  for(int i = 0;i < process_count; i++){
    if(flag != 1){
      if(i == current_index && target == arr_target){
        printf("\033[4m%d\033[0m\t",processes[i]);
        flag = 1;
      }
      else{
        printf("%d\t",processes[i]);
      }
    }
    else{
      printf("%d\t",processes[i]);
    }
  }
  printf("\n");
}
int First_Fit_Algorithm(int memory_block_count,int process_count,int BLOCKS[],int processes[]){
  int memory_blocks[memory_block_count];
  memcpy(memory_blocks,BLOCKS,memory_block_count*sizeof(int));
  for(int i = 0; i < process_count; i++){
    int flag = 0;
    int j = 0;
    int value = processes[i];
    for(j; j < memory_block_count;j++){
      if(value <  memory_blocks[j]){
        memory_blocks[j] -= value;
        flag = 1;
        break;
      }
    }
    if(flag == 0){
      printf("Could not fit process %d into any memory block\n",i);
    }
    else{
      printf("process %d fitted into memory block %d\n",i,j);
    }
  }
  printf("Remaining space in memory: ");
  for(int i = 0 ; i < memory_block_count; i++)
    printf("%d\t",memory_blocks[i]);
  printf("\n");
}
int Worst_Fit_Algorithm(int memory_block_count,int process_count,int BLOCKS[],int processes[]){
  int memory_blocks[memory_block_count];
  memcpy(memory_blocks,BLOCKS,memory_block_count*sizeof(int));
  for(int i = 0 ; i < process_count; i++){
    int flag = 0;
    int j = 0;
    int value = processes[i];
    int worst_block=0,worst_block_index;
    for(j; j < memory_block_count;j++){
      if(value < memory_blocks[j]){
        if(flag == 0)flag = 1;
        if(worst_block < memory_blocks[j]){
          worst_block_index = j;
          worst_block = memory_blocks[j];
        }
      }
    }
    if(flag == 0){
      printf("Could not fit process %d into any memory block\n",i);
    }
    else{
      printf("process %d fitted into memory block %d\n",i,worst_block_index);
      memory_blocks[worst_block_index] -= value;
    }
  }
  printf("Remaining space in memory: ");
  for(int i = 0 ; i < memory_block_count; i++)
    printf("%d\t",memory_blocks[i]);
  printf("\n");
}
int Best_Fit_Algorithm(int memory_block_count,int process_count,int BLOCKS[],int processes[]){
  int memory_blocks[memory_block_count];
  memcpy(memory_blocks,BLOCKS,memory_block_count * sizeof(int));
  for(int i = 0; i < process_count; i++){
    int value = processes[i];
    int flag= 0;
    int best_block,best_block_index;
    int j = 0;
    for(j; j < memory_block_count; j++){
      if(value < memory_blocks[j]){
        if(flag == 0){
          flag = 1;
          best_block = memory_blocks[j];
          best_block_index = j;
        }
        else if(best_block > memory_blocks[j]){
          best_block_index = j;
          best_block = memory_blocks[j];
        }
      }
    }
    if(flag == 0)
      printf("Could not fit process %d in any memory block\n",i);
    else{
      printf("process %d fitted into memory block %d\n",i,best_block_index);
      memory_blocks[best_block_index] -= value;
    }
  }

  printf("Remaining space in memory: ");
  for(int i = 0 ; i < memory_block_count; i++)
    printf("%d\t",memory_blocks[i]);
  printf("\n");
}
int INPUT(int memory_block_count,int process_count,int memory_blocks[],int processes[]){
  for(int i = 0; i < memory_block_count;i++){
    printf("\x1b[2J\x1b[H");
    display_inputs(memory_block_count,process_count,memory_blocks,processes,0,i,0);
    printf("Enter the data: ");
    scanf("%d",&memory_blocks[i]); 
  }
  for(int j = 0; j < process_count;j++){
    printf("\x1b[2J\x1b[H");
    display_inputs(memory_block_count,process_count,memory_blocks,processes,1,j,0);
    printf("Enter the data: ");
    scanf("%d",&processes[j]);
  }
  printf("\x1b[2J\x1b[H");
  display_inputs(memory_block_count,process_count,memory_blocks,processes,1,1,1);
}  
int main(){
  int memory_block_count,process_count;
  printf("\x1b[2J\x1b[HEnter the number of blocks in the memory: ");
  scanf("%d",&memory_block_count);
  printf("Enter the number of processes: ");
  scanf("%d",&process_count);
  int memory_blocks[memory_block_count];
  memset(memory_blocks,0,memory_block_count*sizeof(int));
  int processes[process_count];
  memset(processes,0,process_count*sizeof(int));
  INPUT(memory_block_count,process_count,memory_blocks,processes);
  for(;;){
    int operand;
    printf("Enter the required fit algorithm;\n1)First Fit\n2)Worst Fit\n3)Best Fit\n0)Quit\n::");
    scanf("%d",&operand);
    if (operand != 0) 
      printf("\x1b[2J\x1b[H");
    switch(operand){
      case 0:
        break;
      case 1:
        First_Fit_Algorithm(memory_block_count,process_count,memory_blocks,processes);
        break;
      case 2:
        Worst_Fit_Algorithm(memory_block_count,process_count,memory_blocks,processes);
        break;
      case 3:
        Best_Fit_Algorithm(memory_block_count,process_count,memory_blocks,processes);
        break;
      default:
        printf("Invalid operation!\n");
    }
    if(operand == 0) break;
  }
}
