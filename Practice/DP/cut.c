#include <stdio.h>
#include <stdlib.h>

void OptimizedMatrix(int **,int **,int *p,int N);
void print(int **,int i,int j,int *p);
int **pi;
int main(void){
	int N,l,test,i,j; 
	int *p; //list of cut
	scanf("%d",&test);
	while(test >0){
	scanf("%d",&l);
	scanf("%d",&N);
	p = (int *)malloc(sizeof(int)*(N+2));
	p[0] =0;
	p[N+1] = l;
	for(i=1;i<N+1;i++)
	scanf("%d",&p[i]);
for(i=0;i<N+2;i++){
	printf("%d ",p[i]);
}
	int **table = (int **)malloc(sizeof(int *)*(N+1)); // Main table
	pi = (int **)malloc(sizeof(int *)*(N+1)); // table to store parentization positon
	for(i=0;i<N+1;i++){
	table[i] = (int *)malloc(sizeof(int)*(N+2));
	pi[i] = (int *)malloc(sizeof(int)*(N+2));
	}
	OptimizedMatrix(table,pi,p,N);
	// for(i=0;i<P+1;i++){
	// 	for(j=0;j<P+1;j++){
	// 		printf("%d ",table[i][j]);
	// 	}
	// 	printf("\n");
	// }
	printf("\n");
	for(i=0;i<N+1;i++){
		for(j=0;j<N+2;j++){
			printf("%d ",pi[i][j]);
		}
		printf("\n");
	}
	printf(" Answer = %d\n",table[0][N+1]);
	print(pi,0,N+1,p);
	printf("\n");
	test--;
}
}

void OptimizedMatrix(int **table,int **pi,int *p,int N){
int i,l,k,j,m;
for(i=1;i<N+1;i++){
	table[i-1][i]=0;
	pi[i-1][i] = i;
}
for(l=2;l<=N+1;l++){
	for(i=0;i<=N-l+1;i++){
		//printf("\n");
		j = l+i;
		table[i][j] = 1000000;
		for(k=i+1;k<j;k++){
			//printf("k=%d\n ",k);
			//printf("%d %d =",p[j],p[i]);
			m = table[i][k]+table[k][j]+(p[j]-p[i]);
			if(m<table[i][j]){
				table[i][j] = m;
				//printf("table[i][j]=%d i= %d,j=%d\n",table[i][j],i,j);
				pi[i][j] = k;
			}
		}
	}
}
}

void print(int **pi,int i,int j,int *p){
	if(j==i+1){
		return;
	}
	else{
		printf("cut %d ",p[pi[i][j]]);
		print(pi,i,pi[i][j],p);
			print(pi,pi[i][j],j,p);
}
}