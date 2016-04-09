#include <stdio.h>
#include <stdlib.h>

int max(int a,int b);
int egg(int **table,int i,int j,int *pi,int floo);

int main(void){
int N,K,i,j,max,min,sta,x;
int *pi;
int floo=1;
printf("Enter number of floor\n");
scanf("%d",&N);
printf("Enter number of eggs\n");
scanf("%d",&K);
pi = (int *)malloc(sizeof(int)*(N+1) );
for(i=0;i<N+1;i++){
	pi[i] = -1; 
}
int **table; // stores minimum nuber of trials in the worst case
table = (int **)malloc(sizeof(int *)* (K+1) );
for(i=0;i<K+1;i++){
table[i] = (int *)malloc(sizeof(int)* (N+1) );
}
for(i=0;i<K+1;i++){
	for(j=0;j<N+1;j++){
		table[i][j] = -1;
	}
}
table[0][0]=0;
for(i=1;i<N+1;i++){
table[1][i] = i;
table[0][i] = 0;
}
for(i=1;i<K+1;i++){
table[i][1] = 1;
table[i][0] = 0;
}
printf("Answer is %d\n",egg(table,K,N,pi,floo));
// for(i=0;i<K+1;i++){
// 	printf("\n");
// for(j=0;j<N+1;j++){
// 	printf("%d ",table[i][j]);
// }
// }

for(i=0;i<N+1;i++){
	printf("%d ",pi[i]);
}
printf("\n");


	return 0;
}


int egg(int **table,int i,int j,int *pi,int floo){

	if(table[i][j]!=-1){
		return table[i][j];
	}
	else{
		int l,q,min=10000,sta;
		for(l=1;l<=j;l++){
		if(egg(table,i-1,l-1,pi,j)>egg(table,i,j-l,pi,j)){
			 q = egg(table,i-1,l-1,pi,j);
			 if(min > q){
				min = q;
				sta = floo-l;
				}
		}
		else{
			q = egg(table,i,j-l,pi,floo);
			 if(min > q){
				min = q;
				sta = floo+l;
				}
		}
		
}
table[i][j] = 1+min;
// pi[j] = sta;
printf("Sta = %d\n",sta);
}
return table[i][j];
}

int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
// for(i=2;i<K+1;i++){
// for(j=2;j<N+1;j++){
// 	min = 10000;
// for(x=1;x<=j;x++){
// //printf("\n --------------\n");
// 	max = table[i-1][x-1]; // if egg is broken

// 	if(max < table[i][j-x]){
// 		max = table[i][j-x];
// 	}
// 	//printf("max = %d \n",max);
// 	if(min > max){
// 		min = max;
// 		sta = x;
// 	}
// 	//printf("min = %d",min);
// }
// pi[j] = sta;
// printf("dropped from %d \n",sta+1);
// table[i][j] = 1+min;
// }
// }
// for(i=0;i<K+1;i++){
// 	for(j=0;j<N+1;j++){
// 		printf("%d ",table[i][j]);
// 	}
// 	printf("\n");
// }
// printf("No. of trials required %d\n",table[K][N]);
// printf("Floors are\n");
