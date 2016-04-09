#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void create(int *);
int remainderr(char *s);


int main(void){
	int fibo[300],i,r;
double start, end, executionTime;
char *s = (char *)malloc(sizeof(char));

scanf("%s",s);
start = (double)clock();
create(fibo);
r = remainderr(s);
printf("remainder is %d & fibo is %d \n",r,fibo[r]);
end = (double)clock();
executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
printf("execution time = %f\n",executionTime);


	return 0;
}

void create(int * fibo){
	int i;
fibo[0] = 0;
	fibo[1] = 1;
	for(i=2;i<300;i++){
	fibo[i] = (fibo[i-1] + fibo[i-2])%100;
	}
}

int remainderr(char *s){
	short int *n;
int length,i;
int num = 0;
length = strlen(s);
n = (short int *)malloc(sizeof(short int)*length);
for(i=0;i<length;i++){
	n[i] = s[i] - '0';
	}

i=0;
while(i<length){
while(i<length && num <300){
	num = num*10 + n[i];
	i++;
}
num = num % 300;
}
return num;
}