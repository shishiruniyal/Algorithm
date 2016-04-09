#include<stdio.h>
#include<stdlib.h>
void merge(unsigned long *arr,int lo, int k,int hi);
void mergeSort(unsigned long *arr,int i,int j);
unsigned long  bb[101239]={0};
int main(void){
	int size,i;
	unsigned long *arr;
	scanf("%d\n",&size);
	arr = (unsigned long *)malloc(sizeof(unsigned long)*size);
	for(i=0;i<size;i++){
		scanf("%lu",&arr[i]);
	}
	mergeSort(arr,0,size-1);
	printf("Sorted array \n");
	for(i=0;i<size;i++){
		printf(" %lu \n",arr[i]);
	} 
	return 0;
}


void mergeSort(unsigned long *arr,int i,int j){
if(j-i<2){
	if(arr[i]>arr[j]){
		unsigned long t = arr[i];
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

void merge(unsigned long *arr,int lo,int k,int hi){
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
