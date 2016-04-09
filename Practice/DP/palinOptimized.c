#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Palin(int **,int **,int *p,int N);
char *ch;
int **table;
int main(void){
	int test,i,j,len,l,insert,del,replace; 
	int *cost,p=0;
	scanf("%d",&test);
	while(test >0){

	cost = (int *)malloc(sizeof(int)*3);

	for(i=0;i<3;i++){
		scanf("%d",&cost[i]);
	}

	ch = (char *)malloc(sizeof(char)*100000);
	scanf("%s",ch);
	len = strlen(ch);
	table = (int **)malloc(sizeof(int *)*(3)); // Main table

	for(i=0;i<len+1;i++){
	table[i] = (int *)malloc(sizeof(int)*(len+1));
	}

	for(i=0;i<3;i++){
	table[i][i]=0;
}
for(l=2;l<=len;l++){
	for(i=0;i<=len-l;i++){
		j = (l+i-1);
		del=0,replace=0;insert=0;
		if(ch[i-1]==ch[j-1]){
			//table[i][j] = table[i+1][j-1];
		}
		else{
			insert =cost[0]+table[(i+1)%3][j];
			if(insert > cost[0]+table[(i)%3][(j-1)]){
				insert = cost[0]+table[(i)%3][(j-1)];
			}
			del = cost[1]+table[(i)%3][(j-1)];
			if(del > cost[1]+table[(i+1)%3][(j)]){
				del = cost[1]+table[(i+1)%3][(j)];
			}
			replace = cost[2]+table[(i+1)%3][(j-1)];
			if(insert < del){
				table[i%3][j]=insert;
			}
			else{
				table[i%3][j]=del;
			}
			if(table[i%3][j]>replace){
				table[i%3][j]= replace;
			}
		}
		
	}
table[0] = table[1];
table[1] = table[2];
}
printf(" case : %d : %d\n ",p+1,table[0][len]);
// for(i=0;i<len+1;i++){
// 	for(j=0;j<len+1;j++){
// 		printf("%d ",table[i][j]);
// 	}
// 	printf("\n");
// }
	p++;
	test --;
	}
}



