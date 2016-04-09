#include<stdio.h>
#include<stdlib.h>

void merge(int *, int,int,int);
void mergeSort(int *,int,int);

int main(){
	int size,i;
	int *a;
	scanf("%d",&size);

	a = (int *)malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,size-1);
	printf("sorted array\n");
	for(i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

void mergeSort(int *a,int p,int r){
	int mid;
	if(p<r){
		mid = (p + r)/2;
		mergeSort(a,p,mid);
		mergeSort(a,mid+1,r);
		merge(a,p,mid,r);
	}
}

void merge(int *a,int p, int q,int r){
	int l1,l2,i,j,k;
	l1 = q-p+1;
	l2 = r-q;
	int left[l1];
	int right[l2];
	for(i=0;i<l1;i++){
		left[i] = a[p+i];
	}
	for(i=0;i<l2;i++){
		right[i] = a[q+i+1];
	}
	i=0;
	j=0;
	for(k=p;k<=r;k++){
		if(i<l1 && ((j==l2)||left[i]<right[j])){
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
	}
}
