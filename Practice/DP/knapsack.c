#include <stdio.h>
#include <stdlib.h>
typedef struct Item{
int weight;
int price;
}ITEM;

void case1(int weight,ITEM *it,int items);
void case2(int weight,ITEM *it,int items,int selection);

int main(void){
	int weight,items,i,selection=0;
	ITEM *it;
	printf("Enter weight of knapsack \n");
	scanf("%d",&weight);
	printf("Enter number of items \n");
	scanf("%d",&items);
	it = (ITEM *)malloc(sizeof(ITEM)*items);
	printf("Enter weight and their price \n");
	for(i=0;i<items;i++){
		scanf("%d%d",&(it[i].weight),&(it[i].price));
	}
	for(i=0;i<items;i++){
		selection += it[i].price;
	}
	if(selection >= weight){
		printf("Case 1");
		case1(weight,it,items);
	}
	else{
		printf("case 2");
		case2(weight,it,items,selection);
	}
}

/* table[i][j] = maximum profit that can be made using i items and knapsack of size j */
void case1(int weight,ITEM *it,int items){
	int **table;
	int i,j;
	table = (int **)malloc(sizeof(int *)*(items+1));
	for(i=0;i<items+1;i++){
		table[i] = (int *)malloc(sizeof(int *)*(weight+1));
	}
	for(i=0;i<weight+1;i++){
		table[0][i] = 0; // with no items no profit
	}
	for(i=0;i<items+1;i++){
		table[i][0] = 0; // with no knapsack no profit
	}
	for(i =1;i<items+1;i++){
		int a ,b ;
		for(j =1;j<weight+1;j++){
			a = 0;b =0;
			if(it[i-1].weight <= j){
				a = it[i-1].price + table[i-1][j-it[i-1].weight];
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
	printf("Answer is = %d\n",table[items][weight]);
}
/*table[i][j] = minimum weight of knapsack that should be in order to get a profit of j units */
void case2(int weight,ITEM *it,int items,int selection)
{
int **table;
int i,j;
table = (int **)malloc(sizeof(int *)*(items+1));
for(i=0;i<items+1;i++){
	table[i] = (int *)malloc(sizeof(int *)*(selection+1));
}
for(i=0;i<selection+1;i++){
	table[0][i] = 100000; // with no items and for i profit size of the bag should be infinite 
}
for(i=0;i<items+1;i++){
	table[i][0] = 100000;
}
for(i=1;i<selection+1;i++){
	if(i<=it[0].price)
	table[1][i] = it[0].weight;
	else
		table[1][i] = 100000;
}
for(i = 2;i<items+1;i++){
	int a,b;
	for(j=1;j<selection+1;j++){
		a =100000;b =100000;
		if(j>=it[i-1].price){
			a = it[i-1].weight+table[i-1][j-it[i-1].price];
		}
		b = table[i-1][j];
		if(a<b){
			table[i][j] = a;
		}
		else{
			table[i][j] = b;
		}
	}
}
while(table[items][selection] > weight){
	selection -=1;
}
printf("Answer is %d \n",selection);
}
