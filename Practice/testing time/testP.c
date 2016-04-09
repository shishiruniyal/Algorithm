#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main() {
	clock_t t;
	double start,end,executionTime;
	start = (double)clock();
	int i,j,k,n,s;
	n = 3;
	s=2;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			for(k=0;k<n;k++) {
				s = 2*s + 1;		
		}
		
	}
}
	printf("%d \n",s);
	end = (double)clock();
	executionTime = ((double)(end-start))/CLOCKS_PER_SEC;
	printf(" exection time = %f secs\n",executionTime);
}