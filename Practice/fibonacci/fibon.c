#include<stdio.h>
#include<time.h>
#define MAX 100
int main(void){
	int i,j,a,b,c,range;
double start, end, executionTime;
start = (double)clock();
range = MAX;
a=0;
b=1;
for(i=2;i<=range;i++){
	c = (a+b)%100;
	a=b;
	b=c;
}
printf("%d ",c);
end = (double)clock();
executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
printf("execution time = %f\n",executionTime);
}
