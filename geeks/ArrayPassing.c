#include <stdio.h>

struct node{
	int arr[10];
};
void check(struct node c);

int main(void){
int i;
struct node a;
for(i=0;i<10;i++){
a.arr[i]=i;
}
printf("\nIn main\n");
for(i=0;i<10;i++){
	printf("%d ",a.arr[i]);
}
check(a);

printf("\nIn main\n");
for(i=0;i<10;i++){
	printf("%d ",a.arr[i]);
}

	return 0;
}

void check(struct node c){
int i;
for(i=0;i<10;i++){
	c.arr[i]=99;
}
printf("\nInside function\n");
for(i=0;i<10;i++){
	printf("%d ",c.arr[i]);
}
}
