#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void preProcess(char* pat,int *b,int M);
void matching(char* text,char* pat,int *b,int N,int M);

void preProcess(char * pat,int *b,int M){
	b[0] = -1;
	int i = -1;
	int j=	0;
	while(j<=M){
		while(i>=0 && pat[i]!=pat[j]){
			i = b[i];
		}
		i++;
		j++;
		b[j] = i;
	}
}

void matching(char* text,char* pat,int *b,int N,int M){
	int i=0,j=0;
	while(i<N){
		while(j>=0 && text[i] != pat[j]){
			j = b[j];
		}
		i++;
		j++;
		if(j==M){
			printf("pattern found at position %d\n",i-j);
			j=b[j];
		}
	}
}

int main(void){
	char pat[50];
	char text[100];
	int M,N;
	int* b;
	scanf("%[^\n]",text);
	scanf("%s",pat);
	M = strlen(pat);
	N = strlen(text);
	b = (int *)malloc(sizeof(int)*(M+1));
	preProcess(pat,b,M);
	matching(text,pat,b,N,M);
	return 0;
}