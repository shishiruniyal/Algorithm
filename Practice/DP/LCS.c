#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int i,int j);

int len1,len2;
int **table;
char s1[100];
char s2[100];


int main(void){
	int i,j;
printf("Enter 1st sequence \n");
scanf("%s",s1);
printf("Enter 2nd sequence\n");
scanf("%s",s2);
len1 = strlen(s1);
len2 = strlen(s2);

table = (int **)malloc(sizeof(int *)*(len1+1) );
for(i=0;i<len1+1;i++){
	table[i] = (int *)malloc(sizeof(int)*(len2+1));
}
i=0;
for(j=0;j<len2+1;j++){
	table[i][j] = 0;
}
j=0;
for(i=0;i<len1+1;i++){
	table[i][j] = 0;
}
for(i=1;i<len1+1;i++){
	for(j=1;j<len2+1;j++){
		int max;
		if(s1[i-1]==s2[j-1]){
			table[i][j] = 1+table[i-1][j-1];
		}
		else{
			max = table[i-1][j];
			if(max < table[i][j-1]){
				table[i][j]=table[i][j-1];
			}
			else{
				table[i][j] = max;
			}
		}
	}
}

// for(i=0;i<len1+1;i++){

// 	for(j=0;j<len2+1;j++){
// 		printf("%d",table[i][j]);
// 	}
// 	printf("\n");
// }

printf("Longest common subsequence is %d\n",table[len1][len2]);

print(len1,len2);
printf("\n");
	return 0;
}

void print(int i,int j){
	if(i==0 || j==0){
		return;
	}
if(table[i][j]!=table[i-1][j])
{
	print(i-1,j-1);
	printf("%c",s1[i-1]);
}
else {
	if(table[i][j-1]>table[i-1][j]){
		print(i,j-1);
	}
	else{
		print(i-1,j);
	}
}

}