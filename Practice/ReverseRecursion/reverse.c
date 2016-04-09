#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int value;
	struct node * next;
}NODE;

void printListw(NODE * head);
void reversew(NODE ** head,NODE * curr, NODE *previous);

int main(void){
	char c;
	NODE * head = NULL;
	NODE *p;
while((c=getchar())!='\n'){
	if(c!=' '){
NODE *n = (NODE *)malloc(sizeof(NODE)*1);
n->value = c-'0';
n->next = NULL;
if(head==NULL){
	head = n;
	p = head;
}
else {
p->next = n;
p=n;
}
}
}
printf("Original list\n");
printListw(head);
reversew(&head,head,NULL);
printf("Reversed List is\n");
printListw(head);


	return 0;
}

void printListw(NODE * head){
	while(head != NULL){
		printf("%d ",head->value);
		head = head ->next;
	}
	printf("\n");
}

void reversew(NODE ** head,NODE * curr, NODE *previous){
		if( curr==NULL){
			*head = previous;
			return;
		}
		reversew(head,curr->next,curr);
		curr->next = previous;
}