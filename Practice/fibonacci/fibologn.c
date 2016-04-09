#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int powe(int *,int);
void  MatrixM(int *,int *);

int main(void){
int fibo;
int x[] ={1,1,1,0};
double start, end, executionTime;
start = (double)clock();
fibo = powe(x,301);
end = (double)clock();
executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
printf("execution time = %f\n",executionTime);
printf("fibo is %d \n",fibo);
	return 0;
}
int powe(int *x, int n){
	int y[] = {1,0,0,1};
	int i;
	while(n>0){
		if(n%2!=0){
			MatrixM(y,x);
		}
		MatrixM(x,x);
		n=n/2;
	}
	return y[2];
}

void MatrixM(int *a,int *b){
	int t1,t2,t3,t4;
t1 = (a[0]*b[0] + a[1]*b[2])%100;
t2 = (a[0]*b[1] + a[1]*b[3])%100;
t3 = (a[2]*b[0] + a[3]*b[2])%100;
t4 = (a[2]*b[1] + a[3]*b[3])%100;
a[0] = t1;
a[1] = t2;
a[2] = t3;
a[3] = t4;
}