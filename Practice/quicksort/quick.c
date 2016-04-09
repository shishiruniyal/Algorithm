#include<stdio.h>
#include<stdlib.h>
int partition(unsigned long *,int lo,int hi);
void quickSort(int lo,int hi,unsigned long *);
int size;
int main() {
unsigned long *arr;
int i,lo,hi;
scanf("%d",&size);
arr = (unsigned long *)malloc(sizeof(unsigned long)*size);
for(i=0;i<size;i++) {
scanf("%lu",&arr[i]);
}
lo=0;
hi=size-1;
quickSort(lo,hi,arr);
printf("sorted array\n");
for(i=0;i<size;i++) {
printf(" %lu ",arr[i]);
}
//printf("\n");
}

int partition(unsigned long *arr,int lo,int hi)
{
int i,j;
unsigned long temp,pivot;
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

void quickSort(int lo, int hi,unsigned long *arr) {
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

