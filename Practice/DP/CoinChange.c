#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b);
int main(void){
	int N,M,i,j;
	int **table;
	int *coin;
	scanf("%d%d",&N,&M);
	table = (int **)malloc(sizeof(int *)*(M+1));
	for(i =0;i<M+1;i++){
		table[i] = (int *)malloc(sizeof(int)*(N+1));
	}
	coin = (int *)malloc(sizeof(int)*(M+1));
	coin[0]=0;
	for(i=1;i<M+1;i++){
		scanf("%d",&coin[i]);
	}
	qsort(coin,M+1,sizeof(int),comp);
	for(i=0;i<M+1;i++){
		table[i][0] = 1; // 0 rupee can be paid in 1 way no coin
	}
	for(i=0;i<N+1;i++){
		table[0][i] = 0; // with zero coin you can pay in zero ways
	}
	for(i=1;i<M+1;i++){
		for(j=1;j<N+1;j++){
			if(coin[i] <= j){
				table[i][j] = table[i][j-coin[i]] + table[i-1][j]; 
			}
			else{
				table[i][j] = table[i-1][j];
			}
		}
	}
	for(i=0;i<M+1;i++){
		for(j=0;j<N+1;j++){
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("Answer is %d\n",table[M][N]);
	return 0;
}

int comp(const void *a, const void *b){
	return(*((int *)a)-*((int *)b));
}