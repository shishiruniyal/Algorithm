#include "bst.h"
#include <string.h>
//Insertion of a node

int insert(Node **root,int key,char* data){

	Node *temp,*p,*q;
	int status = 0;
	temp = (Node *)malloc(sizeof(Node));
	if(temp == NULL){
		status = -1;
		return status;
	}
	// puts("cpy");
	// printf("%s\n", data);
	strcpy(temp->data,data);
	// puts("copy done");
	temp->key = key;
	temp->parent = NULL;
	temp->left = NULL;
	temp->right = NULL;
	if(*root == NULL){
		*root =temp;
		return status;
	}
	p = *root;
	//p as current node q as a parent
	q = NULL;
	while(p!=NULL){
		q = p;
		if(key <= p->key){
			p = p->left;
		}
		else{
			p = p->right;
		}
	}
	// At the end of while loop p becomes null and q hold the node where new node to be inserted
	if(key <= q->key){
		q->left = temp;
	}
	else{
		q->right = temp;
	}
	temp->parent = q;
		return status;
}



//Searching a node

char* search(Node *root,int key){
while(root!=NULL){
	if(key == root->key){
		return root->data;
	}
	else if(key < root->key){
		root = root->left;
	}
	else{
		root = root->right;
	}
}
return "Doesn't Exist";
}


//Finding Predecessor of a node
Node* Predecessor(Node * root){
	Node *temp;
	if(root->left != NULL){
		root = root -> left;
	while(root->right){
		root = root -> right;
	}
	return root;
}
else {
	printf("Here \n");
	temp = root->parent;
	while(temp!=NULL && root==temp->left){
		root = temp;
		temp = temp->parent;
	}
}
	return temp;
}


//Intermediate case of deletion only node with no or zero children
int delete(Node **root,int key){
	Node *temp,*predecessor;
	temp = *root;
	while(temp->key!=key){
		if(temp->key >= key){
			temp = temp->left;
		}
		else
			temp = temp->right; 
	}
	if(temp==NULL){
		return -1;
	}
		if(temp->left == NULL){
			transplant(root,temp,temp->right);
			free(temp);
		}

		else if(temp->right == NULL){
			transplant(root,temp,temp->left);
			free(temp);
		}

		else{
				predecessor = Predecessor(temp);
				if(predecessor->parent->key != temp->key){
					transplant(root,predecessor,predecessor->left);
					predecessor->left = temp->left;
					predecessor->left->parent = predecessor;
				}
				transplant(root,temp,predecessor);
				predecessor->right = temp->right;
				predecessor->right->parent = predecessor;

				free(temp);
		}
		return 0;
}

void transplant(Node **root,Node *u, Node *v){
	if(u->parent==NULL){
		(*root) = v;
	}

	else if(u->key <= u->parent->key){
		u->parent->left = v;
	}
	else{
		u->parent->right = v;
	}

	if(v!=NULL){
		v->parent = u->parent;
	}
}


//Inorder traversal through recursion

void InOrder(Node *root){
	if(root==NULL){
		return;
	}
	else{
		InOrder(root->left);
		printf("%d %s, ",root->key,root->data);
		InOrder(root->right);
	}
}