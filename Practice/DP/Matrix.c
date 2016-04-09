#include <stdio.h>
#include <stdlib.h>

void OptimizedMatrix(int **,int **,int *p,int N);
void print(int **,int i,int j);
int main(void){
	int P,i,j; // count of matrices
	int *p; //list of indices
	printf("Matrices count:\n");
	scanf("%d",&P);
	p = (int *)malloc(sizeof(int)*(P+1));
	printf("Enter matrices orders\n");
	for(i=0;i<P+1;i++)
	scanf("%d",&p[i]);
	int **table = (int **)malloc(sizeof(int *)*(P+1)); // Main table
	int **pi = (int **)malloc(sizeof(int *)*(P+1)); // table to store parentization positon
	for(i=0;i<P+1;i++){
	table[i] = (int *)malloc(sizeof(int)*(P+1));
	pi[i] = (int *)malloc(sizeof(int)*(P+1));
	}
	OptimizedMatrix(table,pi,p,P);
	// for(i=0;i<P+1;i++){
	// 	for(j=0;j<P+1;j++){
	// 		printf("%d ",table[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(i=0;i<P+1;i++){
		for(j=0;j<P+1;j++){
			printf("%d ",pi[i][j]);
		}
		printf("\n");
	}
	print(pi,1,P);
}

void OptimizedMatrix(int **table,int **pi,int *p,int N){
int i,l,k,j,m;
for(i=0;i<N+1;i++){
	table[i][i]=0;
	pi[i][i] = i;
}
for(l=2;l<=N;l++){
	for(i=1;i<=N-l+1;i++){
		j = l+i-1;
		table[i][j] = 1000000;
		for(k=i;k<j;k++){
			m = table[i][k]+table[k+1][j]+(p[i-1]*p[k]*p[j]);
			if(m<table[i][j]){
				table[i][j] = m;
				pi[i][j] = k;
			}
		}
	}
}
}

void print(int **pi,int i,int j){
	if(i==j){
		printf("A%d ",i);
		return;
	}
	else{
	printf("(");
		print(pi,i,pi[i][j]);
			print(pi,pi[i][j]+1,j);
			printf(") ");
}
}