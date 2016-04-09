#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void){
	int i = 0;
	char *s = (char *)malloc(sizeof(char));
	while((s[i]=getchar())!='\n'){
		s = (char *)realloc(s,i+2);
		i++;
	}
	short int *n;
	int length;
	int num = 0;
	length = strlen(s);
	n = (short int *)malloc(sizeof(short int)*length);
	for(i=0;i<length;i++){
		n[i] = s[i] - '0';
	}
i=0;
while(i<length){
while(i<length && num <300){
	num = num*10 + n[i];
	i++;
}
num = num % 300;
}
printf("remainder is = %d\n",num);
}