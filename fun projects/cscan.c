#include<stdio.h>
int absoluteValue(int x){
  if(x>0)
    return x;
  else
    return x*-1;
}
void read_disk_position(int n,int headposition,int *t1,int *t2,int queue1[],int queue2[]){
  int temp;
  int temp1 = *t1;
  int temp2 = *t2;
  printf("Enter the disk positions to be read(queue): ");
  for(int i=1;i<=n;i++){
    scanf("%d",&temp);
    if(temp > headposition){
      queue1[temp1]=temp;
      temp1++;
    }else{   
      queue2[temp2]=temp;
      temp2++;
    }
  }
  *t1 = temp1;
  *t2 = temp2;
}
void sort_disk_position(int temp1,int temp2,int queue1[],int queue2[]){
  int temp;
  for(int i=0;i<temp1-1;i++){
    for(int j=i+1;j<temp1;j++){
      if(queue1[i]>queue1[j]){
        temp=queue1[i];
        queue1[i]=queue1[j];
        queue1[j]=temp;
      }
    }
  }
  for(int i=0;i<temp2-1;i++){
    for(int j=i+1;j<temp2;j++){
      if(queue2[i]>queue2[j]){
        temp=queue2[i];
        queue2[i]=queue2[j];
        queue2[j]=temp;
      }
    }
  }
}    
int copy_disk_positions(int queue[],int queue1[],int queue2[],int temp1,int temp2,int headposition,int maxrange){
  int i,j;
  for(i=1,j=0;j<temp1;i++,j++){
    queue[i]=queue1[j]; 
  }
  if(temp2 != 0){

    queue[i]=maxrange;
    queue[i+1]=0; 
    for(i=temp1+3,j=0;j<temp2;i++,j++){
      queue[i]=queue2[j];
    } 
  }
  queue[0]=headposition;
  return i;
}
int Calculate_seek_time(int queue[],int n){
  int difference;
  int seek = 0;
  for(int j=0; j<n-1; j++){   
    difference = absoluteValue(queue[j+1]-queue[j]);
    seek = seek + difference;
    printf("Disk head moves from position %d to %d with Seek %d \n", queue[j], queue[j+1], difference);
  }
  return seek;
}
void main(){
  int queue[25],n,headposition,maxrange,queue1[20],queue2[20],temp1=0,temp2=0;
  float averageSeekTime;
  printf("Enter the maximum range of Disk: ");
  scanf("%d",&maxrange);

  printf("Enter the number of queue requests: ");
  scanf("%d",&n);

  printf("Enter the initial head position: ");
  scanf("%d",&headposition);

  read_disk_position(n,headposition,&temp1,&temp2,queue1,queue2);

  sort_disk_position(temp1,temp2,queue1,queue2);
  int size = copy_disk_positions(queue,queue1,queue2,temp1,temp2,headposition,maxrange);
  int seek = Calculate_seek_time(queue,size);
  averageSeekTime = seek/(float)n;
  printf("Total Seek Time= %d\n", seek);
  printf("Average Seek Time= %f\n", averageSeekTime);
}

