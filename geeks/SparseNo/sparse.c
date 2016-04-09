#include<stdio.h>

int main(void)
{
	int number;
	int flag = 0;
	scanf("%d",&number);
	while(number!=0){
		if(number%2!=0 && (number/2)%2!=0){
			flag =1;
			break;
		}
		number = number>>1;
	}
	if(!flag){
		printf("Sparse number \n");
	}
	return 1;
}