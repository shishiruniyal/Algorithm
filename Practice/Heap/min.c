#include <stdio.h>
#include <stdlib.h>

#define SIZE 10*10*10

void Build(int *arr);
void insert(int *arr,int key);
int extractMin(int *arr);
void decreaseKey(int *arr,int index,int value);
void topDownHeapify(int *arr,int index);
void bottomUpHeapify(int *arr,int index);

int heapLength;

void bottomUpHeapify(int *arr,int index){
	int parent,temp;
	if(index == 0){
		return;
	}
	parent = (index -1)/2;
	while(parent >= 0){
		if(arr[index]<arr[parent]){
			temp = arr[index];
			arr[index] = arr[parent];
			arr[parent] = temp;
		}
		else{
			break;
		}
		index = parent;
		parent = (parent - 1)/2;
	}
}


void topDownHeapify(int *arr , int index){
	int parent, left, right, minimum, temp;

	parent = index;
	left = 2*parent + 1;
	right = 2*parent + 2;

	while(left < heapLength){
			if(right >= heapLength){
				minimum = left;
			}
			else{
				if(arr[right]<arr[left]){
					minimum = right;
				}
				else{
					minimum = left;
				}
			}
		if(arr[minimum] < arr[parent]){
			temp = arr[parent];
			arr[parent] = arr[minimum];
			arr[minimum] = temp;

		left = 2*parent +1;
		right = 2*parent +2;
		parent = (parent -1) /2;
		}
		else{
			break;
		}
	}
}


void insert(int *arr, int key){
	int index;
if(heapLength == SIZE){
	printf("Heap full\n");
	return;
}
arr[heapLength] = key;
index = heapLength;
heapLength++;
bottomUpHeapify(arr,index);

}

int extractMin(int *arr){
int key;
if(heapLength==0){
	printf("heap empty");
	return -1;
}
key = arr[0];
arr[0] = arr[heapLength-1];
heapLength--;
topDownHeapify(arr,0);
return key;
}

void decreaseKey(int *arr,int index,int value){
	if(arr[index] <= value){
		printf("Inappropriate value \n");
		return;
	}
	arr[index] = value;
	bottomUpHeapify(arr,index);
}

void Build(int *arr){
	int i;
	i = ((heapLength-1)-1)/2;
	while(i >=0){
		topDownHeapify(arr,i);
		i = i-1;
	}
}





int main(void){
	int arr = (int *)malloc(sizeof(SIZE)) ;
	int i ;
	heapLength = 0;
	printf("%d\n",extractMin(arr));
	insert(arr,100);
	insert(arr,110);
	insert(arr,10);
	insert(arr,99);
	insert(arr,50);
	insert(arr,1);
	insert(arr,0);
	insert(arr,190);
	decreaseKey(arr,0,-3);
	for(i=0;i<heapLength;i++){
		printf("%d-> ",arr[i]);
	}
	return 1;
}