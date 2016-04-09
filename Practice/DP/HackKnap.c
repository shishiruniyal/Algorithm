#include <stdio.h>
#include <stdlib.h>


void case1(int weight,int *it,int items);

int main(void){
	int weight,items,i,test;
	int *it;
	scanf("%d",&test);
	while(test > 0){
	scanf("%d",&items);
	scanf("%d",&weight);
	it = (int *)malloc(sizeof(int)*items);
	for(i=0;i<items;i++){
		scanf("%d",&it[i]);
	}
		case1(weight,it,items);
		free(it);
		test --;
	}
}

/* table[i][j] = maximum profit that can be made using i items and knapsack of size j */
void case1(int weight,int *it,int items){
	long int **table;
	int i,j;
	table = (long int **)malloc(sizeof(long int *)*(items+1));
	for(i=0;i<items+1;i++){
		table[i] = (long int *)malloc(sizeof(long int *)*(weight+1));
	}
	for(i=0;i<weight+1;i++){
		table[0][i] = 0; // with no items no profit
	}
	for(i=0;i<items+1;i++){
		table[i][0] = 0; // with no knapsack no profit
	}
	for(i =1;i<items+1;i++){
		long int a ,b;
		for(j =1;j<weight+1;j++){
			a = 0;b =0;
			if(it[i-1] <= j){
				a = it[i-1]+ table[i][j-it[i-1]];
			}
			b = table[i-1][j];
			if(a > b){
				table[i][j] = a;
			}
			else{
				table[i][j] = b;
			}
		}
	}
	printf("%ld\n",table[items][weight]);
	for(i=1;i<items+1;i++){
		free(table[i]);
	}
	free(table);
}
