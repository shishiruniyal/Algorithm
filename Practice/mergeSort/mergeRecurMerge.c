#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int lo, int k,int k1,int hi,int t);
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
	printf("\n");
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
	int i1,t=0;
 int k = (i+j)/2;
  mergeSort(arr,i,k);
  mergeSort(arr,k+1,j);
  merge(arr,i,k,k+1,j,0);
  for(i1=i;i1<=j;i1++){
  	arr[i1] = bb[t++];
  }
}
}

void merge(int *arr,int lo,int k,int k1,int hi,int t){
if(lo>k && k1>hi){
	return;
}
else if(lo == k+1){
		bb[t++] = arr[k1++];
		merge(arr,lo,k,k1,hi,t);
	}
	else if(k1 == hi+1){
		bb[t++] = arr[lo++]; 
		merge(arr,lo,k,k1,hi,t);
	}

	else {

		if(arr[lo]<arr[k1]){
			bb[t++] = arr[lo++];
			merge(arr,lo,k,k1,hi,t);
		}
		else{
			bb[t++] = arr[k1++];
			merge(arr,lo,k,k1,hi,t);
		}
	}

/*i=lo;
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
*/
}