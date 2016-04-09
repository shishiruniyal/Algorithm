
#include <stdio.h>
//Method 1:
/*
int main(void){

	int i =1;
	char *c = (char *)&i;
	if(*c==1){
	printf("Little Endian \n");
	}
	else{
	printf("Big Endian\n");
	}
return 0;
}*/


//Method 2:

int main(void){
int i = 0x12345678;
int n,j;
char *c = (char *)&i;
n = sizeof(i);
for(j=0;j<n;j++){
printf("%.2x ",c[j]);
}
}
