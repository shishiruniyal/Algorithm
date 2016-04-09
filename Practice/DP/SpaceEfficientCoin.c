#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b);
int main(void){
	int N,M,i,j;
	long int **table;
	int *coin;
	scanf("%d%d",&N,&M);
	table = (long int **)malloc(sizeof(long int *)*2);
	for(i =0;i<2;i++){
		table[i] = (long int *)malloc(sizeof(long int)*(N+1));
	}
	coin = (int *)malloc(sizeof(int)*(M+1));
	coin[0]=0;
	for(i=1;i<M+1;i++){
		scanf("%d",&coin[i]);
	}
	qsort(coin,M+1,sizeof(int),comp);
	for(i=0;i<2;i++){
		table[i][0] = 1; // 0 rupee can be paid in 1 way no coin
	}
	for(i=0;i<N+1;i++){
		table[0][i] = 0; // with zero coin you can pay in zero ways
	}
	for(i=1;i<M+1;i++){
		for(j=1;j<N+1;j++){
			if(coin[i] <= j){
				table[1][j] = table[1][j-coin[i]] + table[0][j]; 
			}
			else{
				table[1][j] = table[0][j];
			}
		}
		*table = *(table+1);
	}
	printf("%ld\n",table[1][N]);
	return 0;
}

int comp(const void *a, const void *b){
	return(*((int *)a)-*((int *)b));
}