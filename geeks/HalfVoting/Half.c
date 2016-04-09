#include<stdio.h>
#include<stdlib.h>
int MorreVoting(int *arr,int size);
void Test(int candidate,int *arr,int size);



int main(void){
int size,i,candidate;
int *arr;
scanf("%d",&size);
arr = (int *)malloc(sizeof(int)*size);
for(i=0;i<size;i++){
	scanf("%d",&arr[i]);
}

candidate = MorreVoting(arr,size);
Test(candidate,arr,size);

	return 0;
}


int MorreVoting(int *arr,int size){
	int Maj = 0,i;
	int count = 1;
	for(i=1;i<size-1;i++){
		if(arr[Maj] == arr[i]){
			count ++;
		}
		else{
			count--;
		}
		if(count == 0){
			Maj = i;
		}
	}
	return arr[Maj];
}


void Test(int candidate,int *arr,int size){
	int i,count=0;
	for(i=0;i<size-1;i++){
		if(arr[i] == candidate){
			count ++ ;
		}
	}
	if(count = size/2){
		printf("Element is %d\n",candidate);
	}
	else{
		printf("Element is %d\n",arr[size-1]);
	}
}
