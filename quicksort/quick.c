#include<stdio.h>
#include<stdlib.h>
int partition(int *,int lo,int hi);
void quickSort(int lo,int hi,int *);
int size;
int main() {
int *arr;
int i,lo,hi;
scanf("%d",&size);
arr = (int *)malloc(sizeof(int)*size);
for(i=0;i<size;i++) {
scanf("%d",&arr[i]);
}
lo=0;
hi=size-1;
quickSort(lo,hi,arr);
printf("sorted array\n");
for(i=0;i<size;i++) {
printf("%d ",arr[i]);
}
printf("\n");
}

int partition(int *arr,int lo,int hi)
{
int pivot,i,j,temp;
pivot = arr[lo];
i=lo+1;
j=hi;
//printf("pivot = %d i= %d j = %d\n",pivot,i,j );
while(i<j)
{
while(arr[i]<pivot && i<hi)
i++;
while(arr[j]>pivot && j>lo)
j--;
//printf("pivot = %d i= %d j = %d\n",pivot,i,j );
if(i<j) {
temp= arr[i];
arr[i]=arr[j];
arr[j]=temp;
i++;
j--; }
}
if(arr[lo]>arr[j]) {
arr[lo]=arr[j];
arr[j]=pivot;}
return j;
}

void quickSort(int lo, int hi,int *arr) {
int k;
if(lo>=hi)
return;
k=partition(arr,lo,hi);
if(k==0) {
quickSort(k+1,hi,arr);
}
else if(k==hi) {
quickSort(lo,k-1,arr);
}
else {
quickSort(lo,k-1,arr);
quickSort(k+1,hi,arr);}
}

