#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void display(int num_p,int *bt,int *at){  
	printf("\x1b[2J\x1b[HProcessID\t\tBurstTime\t\tArrivalTime\n");
	for(int i = 0; i < num_p;i++){
		printf("%d\t\t\t%d\t\t\t%d\n",i,*(bt+i),*(at+i));
	}
}

int main(){
	int num_p;
	printf("Enter the number of processes: ");
	scanf("%d",&num_p);
	int *burst_time = (int*) malloc (num_p*sizeof(int));
	memset(burst_time,-1,num_p*sizeof(int));
	int *arrival_time = (int*) malloc(num_p*sizeof(int));
	memset(arrival_time,-1,num_p*sizeof(int));
	for (int i = 0; i < num_p;i++){
		display(num_p,burst_time,arrival_time);
		printf("Enter the burst time of the processes: ");
		scanf("%d",burst_time+i);
	}
	for( int i = 0; i < num_p; i++){
		display(num_p,burst_time,arrival_time);
		printf("Enter the arrival time of the processes: ");
		scanf("%d",arrival_time+i);
	}
  display(num_p,burst_time,arrival_time);
}
