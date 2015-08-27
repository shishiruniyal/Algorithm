#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *arr,int lo,int hi);
void Qsort(int *arr,int lo,int hi);

int main(void){
int i,size,*arr;
scanf("%d",&size);

arr =(int *)malloc(sizeof(int)*size);
for(i=0;i<size;i++){
scanf("%d",&arr[i]);
}
Qsort(arr,0,size-1);

printf("Sorted Array\n");

for(i=0;i<size;i++){
printf("%d ",arr[i]);
}
printf("\n");

	return 0;
}

void Qsort(int *arr,int lo,int hi){

srand((unsigned int)time(NULL));
int p,temp,k,i;
if(hi - lo < 2){
	if(arr[hi]<arr[lo]){
		temp = arr[hi];
		arr[hi] = arr[lo];
		arr[lo] = temp;
	}
	return;
}

p = lo+rand()%(hi-lo+1);
printf("random number generated is = %d\n",p);
temp =arr[lo];  //putting the pivot to the first position
arr[lo] = arr[p];
arr[p] = temp;
for(i=lo;i<=hi;i++){
printf("%d ",arr[i]);
}
printf("\n");
k = partition(arr,lo,hi);
Qsort(arr,lo,k-1);
Qsort(arr,k+1,hi);
}


int partition(int *arr,int lo, int hi){

	int i,j,pivot,temp;
	i = lo+1;
	j=hi;
	pivot = arr[lo];
	while(i<j){
		while(arr[i]<=pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[lo] = arr[j];
	arr[j] = pivot;
	if(j==0){
		j++;
	}
	if(j==hi){
		j--;
	}
	return j; 
}