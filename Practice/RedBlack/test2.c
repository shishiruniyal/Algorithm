#include "redBlack.h"
#include <stdlib.h>
#include <stdio.h>



void search(node **root,long int data,node *nil){
node *temp;
temp = *root;
while(temp!=nil && (temp->data)!=data){
if(temp->data > data){
	temp = temp->left;
}
else{
	temp = temp->right;
}
}
if(temp!=nil){
	printf("Match Found %ld\n",data);
}
else{
	printf(" NO Match Found\n");
}
}


node *newNode(long int data,node *nil){
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = 	nil;
	temp->right = 	nil;
	temp->count = 1;
	temp->black = 0; //making a node red intially
	return temp;
}


//Inserting a node
int insert(node **root,node *z,node *nil){
		node *child;
		node *parent;
		child = *root;
		parent = nil;
		//Inorder(*root);
		while(child!=nil){
			child->count = (child->count) + 1; //increasing no of nodes along the path
			//puts("Here");
			parent = child;
			if(z->data <= child->data){
				child = child->left;
			}
			else{
				child = child->right;
			}
		}
		z->parent = parent;
		if(parent == nil){
			*root = z;
		}
		else if(z->data <= parent->data){
			parent->left = z;
		}
		else{
			parent->right = z;
		}
		z->left = nil;
		z->right = nil;
		z->black = 0;
		RepairTree(root,z,nil);

		return 0;
	}


	void RepairTree(node **root,node *child,node *nil){

		node *parent, *grandParent, *uncle;
			//printf("child = %ld , parent color = %d",child->data,child->parent->black);
		while(!(child->parent->black)){
		//	printf("child = %ld, parent = %ld \n",child->data,child->parent->data);
			parent = child->parent;
			grandParent = parent->parent;

			if(grandParent->left == parent){  //left left
				uncle = grandParent->right;
				if(!(uncle->black)){    //case 1 uncle is red
					parent->black = 1;
					uncle->black = 1;
					grandParent->black = 0;
					child = grandParent;
				}
				else{ 
				if(child == parent->right){ // case 2 and case 3 uncle is black
					child = parent;
					leftRotate(root,child,nil);
					parent = child->parent;
					grandParent = parent->parent;
				}
				parent->black = 1;
				grandParent->black = 0;
				rightRotate(root,grandParent,nil);
				break;
			}
			}

			else{ // right right
				uncle = grandParent->left;
				if(!(uncle->black)){    //case 1 uncle is red
					parent->black = 1;
					uncle->black = 1;
					grandParent->black = 0;
					child = grandParent;
				}
				else {
				if(child == parent->left){ // case 2 and case 3 uncle is black
					child = parent;
					rightRotate(root,child,nil);
					parent = child->parent;
				grandParent = parent->parent;
				}
				
				parent->black = 1;
				grandParent->black =0;
				leftRotate(root,grandParent,nil);
			}
			}

		}

		(*root)->black = 1;

	}



//Inorder traversal

// void Inorder(node *root){
// 		if(root == NULL){
// 			return;
// 		}
// 		Inorder(root->left);

// 		printf("<%ld,%ld,%d> ",root->data,root->count,root->black);

// 		Inorder(root->right);

// }




// // Deletion 

long int delete(node **root,long int data,node *nil){

	node *predecessor,*z,*y,*x;

	long int l,r;

	short int color;

//search for node to be deleted
	z = *root;

	while(z!=nil){

		if(z->data == data)
			break;

		else if(z->data > data){
			
			z = z->left;
		}
		else{
			
			z = z->right;
		}
	}
		if(z == nil){

			return -1;
		}

	y = z;// for holding the node to be deleted and x stores child of the node which replaces the node to be deleted

	color = y->black;

	if(z->left == nil){
		x = z->right; // x replaces y
		transplant(root,z,z->right,nil);
		//free(z);
	}

	else if(z->right == nil){
		x = z->left;
			transplant(root,z,z->left,nil);
		free(temp);
	}
	else{
		y = sucessor(z->right,nil);
		color = y->black;
		x = y->right;
		//printf("y->parent = %ld node = %ld , left = %ld, right = %ld\n",y->parent->data,temp->data,temp->left->data,temp->right->data);
		
		if(y->parent == z ){
			x->parent = y;
		}
			else{
			transplant(root,y,y->right,nil);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(root,z,y,nil);
		y->left = z->left;
		y->left->parent = y;
		y->black = z->black;
		//free(temp);
	}
	//only if deleted node color is black 
	if(color == 1){
		correctDelete(root,x,nil);
	}

	return 0;
}

void correctDelete(node **root,node *x,node *nil){

	node *sibling,*y,*q;

	while(x!=(*root) && (x->black)==1){
			// if node is left of parent
		//printf("Inside x = %ld, parent = %ld  x->parent->right = %ld\n",x->data,x->parent->data,x->parent->right->data);
		if(x == x->parent->left){
			//puts("yahaya");
			//printf("x = %ld ,x->parent=%ld x->parent->right = %ld\n",x->data,x->parent->data,x->parent->right->data);
			sibling = x->parent->right;
			//printf("sibling  = %ld\n",sibling->data);
			//case 1 sibling red
			if((sibling->black) == 0){
				//puts("Here1212211");
				sibling->black = 1;

				x->parent->black = 0;
				leftRotate(root,x->parent,nil);
				sibling = x->parent->right;
			}
			//case 2 both left and right of sibling are black
			if(sibling->left->black==1 && sibling->right->black==1 ){
				sibling->black= 0;
				x = x->parent;
			}
			// case 3 sibling is black
			// if its left child is red
			else {
				if (sibling->right->black == 1)
			{
				// make sibling left child black and itself red
				sibling->left->black = 1;

				sibling->black = 0;
				rightRotate(root,sibling,nil);
				sibling = x->parent->right;
			}
			//case 4 sibling right child red

			sibling->black = x->parent->black;
			x->parent->black = 1;
			sibling->right->black =1;
			leftRotate(root,x->parent,nil);
			x = *root;
		}
	}

			//if node is right of parent
		else{
			sibling = x->parent->left;
			//printf("sibling  = %ld\n",sibling->data);
			//case 1 sibling red
			if((sibling->black) == 0){
				//puts("Here1212211");
				sibling->black = 1;
				x->parent->black = 0;
				rightRotate(root,x->parent,nil);
				sibling = x->parent->left;
			}
			//case 2 both left and right of sibling are black
			if(sibling->left->black==1 && sibling->right->black==1 ){

				sibling->black= 0;
				
				x = x->parent;
			}
			// case 3 sibling is black
			// if its right child is red
			else {
				if (sibling->left->black == 1)
			{
				// make sibling right child black and itself red
				sibling->right->black = 1;
				
				sibling->black = 0;
				leftRotate(root,sibling,nil);
				sibling = x->parent->left;
			}
			//case 4 sibling right child red
		
			sibling->black = x->parent->black;
			x->parent->black = 1;
			sibling->left->black =1;
			rightRotate(root,x->parent,nil);
			x = *root;
		}
	}
}
	x->black = 1;
}


void transplant(node **root,node *u,node *v,node *nil){
	if(u->parent == nil){
		*root  = v;
	}
	else if(u == u->parent->left){
			u->parent->left = v;
		}
		else{
			u->parent->right = v;
		}

		v->parent = u->parent;
	}



node * sucessor(node *root,node *nil){
node *temp,*p = NULL;
temp = root;
while(temp!=nil){
	p = temp;
	temp = temp->left;
}
return p;
}


void leftRotate(node **root,node *x,node *nil){
	node *y = x->right;
	x->right = y->left;
	if(y->left!=nil)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == nil){
		*root = y;
	} 
	else if(x == x->parent->left){
			x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
}

void rightRotate(node **root,node *x,node *nil){
	node *y;
	y = x->left;
	x->left = y->right;
	if(y->right!=nil){
		y->right->parent = x;
	}
	y->parent = x->parent;
	if(x->parent == nil){
		*root = y;
	} 
	else if(x == x->parent->right){
			x->parent->right = y;
	}
	else{
		x->parent->left = y;
	}

	y->right = x;
	x->parent = y;
}