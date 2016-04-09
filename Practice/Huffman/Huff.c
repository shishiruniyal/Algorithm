#include <stdio.h>
#include <stdlib.h>
#include "huff.h"

struct node* first = NULL;
int n;
void TakeInput(){
	int i;
	struct node * temp;
	printf("Enter number of characters \n");
	scanf("%d",&n);
	printf("Inputted = %d\n",n);
	printf("Enter Character and there frequency \n");
	for(i=1;i<=n;i++){
		temp = (struct node*)malloc(sizeof(struct node));
		scanf("\n%c%d",&(temp->c),&(temp->frequency));
		temp->next = first;
		first = temp;
		printf("Printing \n");
		printf("charcter = %c,frequency = %d\n",first->c,first->frequency);
	}
}

int main(){
	TakeInput();
	BuildHeap(first,n);
	printf("Heap Build \n");
}