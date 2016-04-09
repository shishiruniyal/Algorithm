#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b);
int main(void){
int i,size,flag=0,target,j,key;
int *a;
scanf("%d",&size);
a = (int *)malloc(sizeof(int)*size);
for(i=0;i<size;i++){
scanf("%d",&a[i]);
}
scanf("%d",&target);
qsort(a,size,sizeof(int),comp);
flag = search(a,0,size-1,target);
if(flag == 1){
	printf("pair exists\n");
}
return 0;
}

int comp(const void *a,const void *b){
int *a1 = (int *)a;
int *a2 = (int *)b;
return *a1-*a2;
}

int search(int *a,int lo,int r,int target){
while(lo<r){
if(a[lo]+a[r]==target){
	return 1;
}
else if(a[lo]+a[r] > target){
	r--;
}
else{
	lo++;
}
}
return 0;
}