#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int lo, int k,int hi);
void mergeSort(int *arr,int i,int j);
int bb[100]={0};
int main(void){
	int size,i;
	int *arr;
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	mergeSort(arr,0,size-1);
	printf("Sorted array \n");
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	} 
	return 0;
}


void mergeSort(int *arr,int i,int j){
if(j-i<2){
	if(arr[i]>arr[j]){
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}
}

else{
  int k = (i+j)/2;
  mergeSort(arr,i,k);
  mergeSort(arr,k+1,j);
  merge(arr,i,k,j);
}
}

void merge(int *arr,int lo,int k,int hi){
int t =0;
int i,j;
i=lo;
j=k+1;
while(i<=k && j<=hi){
	if(arr[i]<arr[j]){
		bb[t++] = arr[i++];
	}
	else{
		bb[t++] = arr[j++];
	}
}
while(i<=k){
	bb[t++] = arr[i++];
}
while(j<=hi){
	bb[t++] = arr[j++];
}
i=lo;
t=0;
while(i<=hi){
	arr[i++] = bb[t++];
}

}
