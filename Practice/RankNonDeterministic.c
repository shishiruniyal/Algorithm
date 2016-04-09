#include<stdio.h>
#include<stdlib.h>

int FindElement(int *arr, int lo, int hi);
int partition(int *arr,int lo,int hi);

int main(void){
int n,m,i,rank;
int *arr;
int *find;

scanf("%d",n);
scanf("%d",m);

arr = (int *)malloc(sizeof(int)*n);
for(i=0;i<n;i++){
	scanf("%d",arr[i]);
}

while(m>0){
	int element = 0;
	scanf("%d",rank);
	element = FindElement(arr,0,n-1);
	printf("Element with rank %d = %d \n",element);
	m--;
}

	return 0;
}



int FindElement(int *arr,int lo,int hi){


}

int partition(int *arr,int lo,int hi){
int pivot = arr[hi];
int i,j;
i = lo-1;
for(j=0;j<hi-1;j++)

}