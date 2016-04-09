#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(void){
	int test;
// char* one = "Shishir";
// char* two = "Uniyal"; 
int status,i=1;
char* string = (char*)malloc(sizeof(char)*2000);
const char delim[2] =" ";
char *token;
char *pri;
scanf("%d",&test);
while(i<=test){
	scanf("\n%[^\n]s",string);
	token = strtok(string,delim);
	while(token!=NULL){
		status=push(token);
		token = strtok(NULL,delim);
	}
	pri = (char*)pop();
	printf("Case #%d: ",i);
	while(pri!=NULL){
		printf("%s ",pri);
		pri = (char*)pop();
	}
	printf("\n");
	i++;
}
return 0;
}
