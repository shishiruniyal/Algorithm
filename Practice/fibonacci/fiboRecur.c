#include<stdio.h>
#include<time.h>

int rec(int n);

int main(void){
double number,start, end, executionTime;
start = (double)clock();
scanf("%lf",&number);
printf("%d ",rec(number));
end = (double)clock();
executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
printf("\nexecution time = %f\n",executionTime);
	return 0;
}

int rec(int n){
	if(n<2)
		return n;
	else
		return((rec(n-1)+rec(n-2))%100);
}