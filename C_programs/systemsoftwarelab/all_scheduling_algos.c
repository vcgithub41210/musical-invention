#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display(int num_p,int **array){  
	printf("\x1b[2J\x1b[HProcessID\tBurstTime\t\tArrivalTime\t\tCompletionTime\t\tWaitingTime\tTurnAroundTime\n");
	for(int i = 0; i < num_p;i++){
    printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t%d\n",i+1,*(*(array)+i),*(*(array + 1)+i),*(*(array + 2)+i),*(*(array + 3)+i),*(*(array + 4)+i));
	}
}
void sort_at(int num_p,int **array){
  for (int i = 0; i < num_p-1;i++){
    int min = i;
    for(int j = i+1;j < num_p;j++){
      if(*(*(array+1)+j) < *(*(array+1)+min)){
    min = j; 
      }
    }
    if (min != i){
    int temp = *(*(array+1)+min);
    *(*(array+1)+min) = *(*(array+1)+i);
    *(*(array+1)+i) = temp;
    int temp1 = *(*(array)+min);
    *(*(array)+min) = *(*(array)+i);
    *(*(array)+i) = temp1;
    }
  }
  for(int i = 0; i < num_p;i++){
    *(*(array+3)+i) = -(*(*(array+1)+i));
  }
}
//functions
void FCFS(int num_p,int **array){
  // array+2 ==> completion time
  // array + 3 ==> waiting time
  // array + 4 ==> turn arount time
  *(*(array+2)) = *(*(array));
  for(int i = 1; i < num_p; i++){
    int prev_ct = *(*(array+2)+i-1);
    *(*(array+2)+i) = prev_ct + *(*(array)+i);
    *(*(array+3)+i) += prev_ct;
  }
  for (int i = 0; i < num_p;i++){
    *(*(array+4)+i) = *(*(array)+i) + *(*(array+3)+i);
  }
}
void SJF(){}
void SRTF(){}
void Round_Robin(){}
void Priority(){}

//main function
int main(){
	int num_p;
	printf("Enter the number of processes: ");
	scanf("%d",&num_p);

  //arrays initialisation
  int **array = (int**)malloc(5*sizeof(int*));
  for(int i = 0; i < 5;i++){
    *(array+i) = (int*)malloc(num_p*sizeof(int));
    memset(*(array+i),-1,num_p*sizeof(int));
  }
  //end

	for (int i = 0; i < num_p;i++){
    display(num_p,array);
		printf("Enter the burst time of the processes: ");
		scanf("%d",*(array)+i);
	}
	for( int i = 0; i < num_p; i++){
    display(num_p,array);
		printf("Enter the arrival time of the processes: ");
		scanf("%d",*(array+1)+i);
	}
  sort_at(num_p,array);
  int choice;
  do{
    display(num_p,array);
    if(choice == -1)
        printf("Invalid option: ");
    printf("\n1)FCFS\t2)SJF\t3)SRTF\t4)Round_Robin\t5)Priority\t0)QUIT\n");
    printf("Enter the algorithm to perform: ");
    scanf("%d",&choice);
    switch(choice){
      case 0:
        continue;
      case 1:
        FCFS(num_p,array);
        break;
      case 2:
        SJF();
        break;
      case 3:
        SRTF();
        break;
      case 4:
        Round_Robin();
        break;
      case 5:
        Priority();
        break;
      default:
        choice = -1;
    }
  }
  while(choice != 0);
}
