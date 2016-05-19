#include <stdlib.h>
#include <stdio.h>
struct node{
	int info;
	struct node*left,*right;
};
void InOrder(struct node *root);
int main(void){
	struct node *root = (struct node*)malloc(sizeof(struct node));
	root->info = 10;
	root->left = (struct node*)malloc(sizeof(struct node));
	root->left->info = 20;
	root->right= (struct node*)malloc(sizeof(struct node));
	root->right->info = 30;
	root->left->left = (struct node*)malloc(sizeof(struct node));
	root->left->left->info = 40;
	root->right->right = (struct node*)malloc(sizeof(struct node));
	root->right->right->info = 50;
	Delete(root);
	puts("tree deleted \n");
	return 0;
}

Delete(struct node* root){
	if(root==NULL){
		return;
	}
Delete(root->left);
root->left=NULL;
Delete(root->right);
root->right = NULL;
struct node*temp = root;
root = NULL;
free(temp);
}

//Inorder traversal through recursion

void InOrder(struct node *root){
	if(root==NULL){
		return;
	}
	else{
		InOrder(root->left);
		printf(" %d ",root->info);
		InOrder(root->right);
	}
}