#include <stdio.h>
#define max_count 100

void heapify(int array[],int range,int index){
	int temp;
	int largest = index;
	int left = (2*index) + 1;
	int right = (2*index) + 2;
	if (left < range && array[left] > array[largest]){
		largest = left;
	}
	if (right < range && array[right] > array[largest]){
		largest = right;
	}
	if (largest != index){
		temp = array[largest];
		array[largest] = array[index];
		array[index] = temp;
		heapify(array,range,largest);
	}
}
void build_heap(int array[],int length){
	for (int i = length/2 - 1; i >= 0; i--){
		heapify(array,length,i);
	}
}
void heap_sort(int array[],int length){
	build_heap(array,length);
	int temp;
	for (int i = length-1; i >= 0; i--){
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapify(array,i,0);
	}
}
int Search_head(int request[],int target,int length){
	int start = 0;
	int end = length-1;
	while(start < end){
		int middle = (start + end)/2;
    if(request[middle] < target)
      start = middle+1;
    else
      end = middle-1;
	}
	return end;
}
int Calculate_seek_time(int request[],int headposition,int max_range,int length){
	int index = Search_head(request,headposition,length);
	if (index == 0 && headposition < request[index]){
		return request[length-1] - headposition;
	}else{
		return 2*max_range - headposition + request[index];
	}
}
int main(){
	int max_range,length,headposition;
	printf("Enter the maximum disk range: ");
	scanf("%d",&max_range);
	printf("Enter the number of requests: ");
	scanf("%d",&length);
	int request[length];
	for (int i = 0; i < length; i++){
		printf("Enter a valid request track for %dth request",i);
		scanf("%d",&request[i]);
		while(request[i] > max_range){
			printf("Enter a valid request track for %dth request",i);
			scanf("%d",&request[i]);
		}
	}
	heap_sort(request,length);
	printf("Enter the headposition: ");
	scanf("%d",&headposition);
	int seek_time = Calculate_seek_time(request,headposition,max_range,length);
	printf("%d",seek_time);
}
