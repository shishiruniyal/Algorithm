#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	int i,size,max=0,min=0,target;
	int *a;
short int *flag;
scanf("%d",&size);
a = (int *)malloc(sizeof(int)*size);
for(i=0;i<size;i++){
	scanf("%d",&a[i]);
}
scanf("%d",&target);
for(i=0;i<size;i++){
if(a[i]<a[min]){
	min = i;
}
if(a[i]>a[max]){
	max = i;
}
}
if(a[min]<0){
	int temp =abs(a[min]);
for(i=0;i<size;i++){
	a[i] = a[i]+temp;
}
target = target + (2*temp);
}
flag = (short int *)calloc(sizeof(short int),a[max]+1);
for(i=0;i<size;i++){
	int temp;
	temp = target-a[i];
	if(temp>0 && flag[temp]==1){
		printf("pair exist\n");
		break;
	}
flag[a[i]]=1;
}
	return 0;

}

