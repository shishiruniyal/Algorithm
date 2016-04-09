#include <stdio.h>

void test(int *);
int main(void){
int i;
test(&i);
	return 0;
}
void test(int *i){
	int j;
	int *p;

	p=&j;

	printf("main = %p, test = %p \n",i,p);

	if(p<i){
		printf("Growing downard \n");
	}
	else{
		printf("Growing upward\n");
	}
}
