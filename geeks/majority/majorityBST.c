#include<stdio.h>
#include<stdlib.h>
void add(int *arr,int size);
struct node {
	int value;
	int count;
	struct node *left;
	struct node *right;
};

int main(void){
	int size,i;
	int *arr;
	scanf("%d",&size);
	arr = (int *)malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	add(arr,size);
	return 0;
}

void add(int *arr,int size){

	int i;
	struct node * root = NULL;
	for(i=0;i<size;i++){
		short int flag =0;
	if(root == NULL){
	root = (struct node *)malloc(sizeof(struct node));
	root->value = arr[i];
	root->count = 1;
	root->left = NULL;
	root->right = NULL;
	}
	else{
		struct node *p,*q;
	p=root;
	while(p!=NULL){
	if(arr[i] <= p->value){
		if(arr[i] == p->value){
		flag =1;
		if(p->count >= size/2){
		printf("majority element is = %d\n",p->value);
		break;
		}
			else {
			
			p->count ++;
			
			break;
			}
	}
	q=p;
	p = p->left;
	}
	else if(arr[i] > p->value){
	q=p;
	p=p->right;
	}
	}
	if(!flag){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->value = arr[i];
	n->count = 1;
	n->left = NULL;
	n->right = NULL;
	if(arr[i]>q->value){
	q->right = n;
	}
	else{
	q->left = n;
	}
	}
	}
	}
}