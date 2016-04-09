#include "redBlack2.h"
#include <stdlib.h>
#include <stdio.h>



void search(node **root,long int data){
node *temp;
temp = *root;
while(temp!=NULL && (temp->data)!=data){
if(temp->data > data){
	temp = temp->left;
}
else{
	temp = temp->right;
}
}
if(temp!=NULL){
	printf("Match Found %ld\n",data);
}
else{
	printf(" NO Match Found\n");
}
}


node * newNode(long int data){
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->count = 1;
	temp->black = 0; //making a node red intially
	return temp;
}


//Inserting a node
int insert(node **root, long int data){
		node *child;
		node *parent =NULL;
		child = *root;
		while(child!=NULL){
			child->count = (child->count) + 1; //increasing no of nodes along the path
			parent = child;
			if(data <= child->data){
				child = child->left;
			}
			else{
				child = child->right;
			}
		}

		if(parent==NULL){
			*root = newNode(data);
			(*root)->parent = NULL;
			(*root)->black = 1;
			return 0;
		}
		child = newNode(data);
		child->parent = parent;	

		if(parent->data >= data){
			parent->left = child;
		}

		else{
			parent->right = child;
		}

		RepairTree(root,child);
		return 0;
	}


	void RepairTree(node **root,node *child){

		node *parent, *grandParent, *uncle;
			//printf("child = %ld , parent color = %d",child->data,child->parent->black);
		while( (child->parent!=NULL) && !(child->parent->black)){
			
			parent = child->parent;

			grandParent = parent->parent;

			if((grandParent->left)!=NULL && grandParent->left->data == parent->data){  //left left
				
				uncle = grandParent->right;

				if( uncle!=NULL && !(uncle->black)){    //case 1 uncle is red
					
					parent->black = 1;
					
					uncle->black = 1;
					
					grandParent->black  = 0;
					child = grandParent;


				}

				else{ // case 2 and case 3 uncle is black

						if((parent->left!=NULL) && parent->left->data == child->data){

						ZigZig(root , grandParent , parent , child);

						parent->black = 1;

						grandParent->black = 0;

						break;

					}

					else{

						ZigZag(root , grandParent , parent , child);

						child->black = 1;

						grandParent->black = 0;

						break;
					}
				}

			}

			else{ // right right

				uncle = grandParent->left;

				if( uncle!=NULL && !(uncle->black)){    //case 1 uncle is red
					
					parent->black = 1;
					uncle->black = 1;
					grandParent->black = 0;
					child = grandParent;
				}

				else{ // case 2 and case 3 uncle is black

						if( (parent->right!=NULL) && parent->right->data == child->data){

						ZigZig(root , grandParent , parent , child);

						parent->black = 1;

						grandParent->black = 0;

						break; 

					}

					else{

						ZigZag(root , grandParent , parent , child);

						child->black = 1;

						grandParent->black = 0;

						break;
					}
				}



			}

		}

		(*root)->black = 1;

	}





void ZigZig(node **root,node *grandParent,node *parent,node *child){

long int l,r;

parent->parent = grandParent->parent;

if(grandParent->parent == NULL){
	
	*root = parent;
}
else{
	if(grandParent->parent->left->data == grandParent->data){
		
		grandParent->parent->left = parent;
	}
	else{
		
		grandParent->parent->right = parent;
	}
}
//zig zig all in right
if((grandParent->right!=NULL && grandParent->right->data == parent->data  && (child==NULL || parent->right->data == child->data))){
	
	grandParent->right = parent->left;
	
	if(parent->left!=NULL)
		parent->left->parent = grandParent;
	
	parent->left = grandParent;
	
	grandParent->parent = parent;
}
else{ //all left
	
	grandParent->left = parent->right;
	
	if(parent->right!=NULL)
		parent->right->parent = grandParent;
	
	parent->right = grandParent;
	
	grandParent->parent = parent;
}
if(grandParent->left == NULL && grandParent->right ==NULL){
		
		l = 0;
		
		r = 0;
	}
	else if(grandParent->left!=NULL && grandParent->right==NULL){
		
		l = grandParent->left->count;
		
		r = 0;
	}
	else if(grandParent->right!=NULL && grandParent->left==NULL){
		
		r = grandParent->right->count;
		
		l = 0;
	}
	else{
		
		l = grandParent->left->count;
		
		r = grandParent->right->count;
	}
	grandParent->count =l + r + 1;
		if(child==NULL){
			parent->count = (grandParent->count) + 1;
		}
		else{
	parent->count = (grandParent->count) + (child->count) + 1;
}
}


void ZigZag(node **root,node *grandParent,node *parent,node *child){

	long int l,r;

	child->parent = grandParent->parent;
	
	if(grandParent->parent == NULL){	
	*root = child;
	}
else{
	if(grandParent->parent->left->data == grandParent->data){
					
		grandParent->parent->left = child;
	}
	else{
					
		grandParent->parent->right = child;
	}
}
grandParent->parent = child;
parent->parent = child;

	//right and then left
		if(grandParent->right!=NULL && grandParent->right->data == parent->data){

			grandParent->right = child->left;

			if(grandParent->right !=NULL)
				grandParent->right->parent=grandParent;
			
			parent->left = child->right;
			
			if(parent->left!=NULL)
				parent->left->parent=parent;
			
			child->left = grandParent;
			
			child->right = parent;

		}
//left and then right
		else{
						
			grandParent->left = child->right;

			if(grandParent->left!=NULL)
				grandParent->left->parent=grandParent;

			parent->right = child->left;
			
			if(parent->right !=NULL)
				parent->right->parent=parent;
			
			child->left = parent;

			child->right = grandParent;		

		}

//count of grandparent
		if(grandParent->left == NULL){
						

			if(grandParent->right == NULL){
			grandParent->count = 1;
		}
		else{
					
			grandParent->count = grandParent->right->count +1;
		}
		}
		else if(grandParent->right == NULL){
						

			if(grandParent->left == NULL){
							

				grandParent->count = 1;
			}
			else{
							
				grandParent->count = grandParent->left->count +1;
			}
		}

		else{

			grandParent->count = grandParent->left->count > grandParent->right->count + 1;
		}

//count of parent
if(parent->left == NULL){
			if(parent->right == NULL){
			parent->count = 1;
		}
		else{
			parent->count = parent->right->count +1;
		}
		}
		else if(parent->right == NULL){
			if(parent->left == NULL){
				parent->count = 1;
			}
			else{
				parent->count = parent->left->count +1;
			}
		}
		else{
			parent->count = parent->left->count + parent->right->count + 1;
		}

//count of child
		child->count = child->left->count + child->right->count + 1;

}




//Inorder traversal

void Inorder(node *root){
		if(root == NULL){
			return;
		}
		Inorder(root->left);

		printf(" <%ld,%ld,%d> ,",root->data,root->count,root->black);

		Inorder(root->right);

}




// Deletion 

long int delete(node **root,long int data){
	//printf("call ayay hai\n");
	node *temp,*predecessor,*z,*y,*x,*parent;
	int left = 0,right = 0;
	long int l,r,HeightBefore,HeightAfter;

	short int color;

//search for node to be deleted
	temp = *root;

	while(temp!=NULL){

		if(temp->data == data)
			break;

		else if(temp->data >= data){
			
			temp = temp->left;
		}
		else{
			
			temp = temp->right;
		}
	}
		if(temp == NULL){

			return -1;
		}

	y = temp;// for holding the node to be deleted and x stores child of the node which replaces the node to be deleted

	puts("qwerty");
	color = temp->black;

	if(temp->left == NULL){
		parent = temp->parent;

		if(parent!=NULL){
		if( (parent->left)!=NULL  &&  parent->left->data == temp->data){
			printf("parent ->left = %ld \n",parent->left->data);
			left = 1;
		}
		else{
			printf("parent ->right = %ld \n",parent->right->data);
			right = 1;
		}
	}
		x = temp->right; // x replaces y

		transplant(root,temp,temp->right);

		free(temp);
	}

	else if(temp->right == NULL){
		puts("yaha");
		parent = temp->parent;
		if(parent!=NULL){
		if( (parent->left)!=NULL  &&  parent->left->data == temp->data){
			left = 1;
		}
		else{
			right = 1;
		}
	}
		x = temp->left;
		
		transplant(root,temp,temp->left);

		free(temp);
	}

	else{
		printf("temp = %ld \n",temp->data);
		puts("yaha 2");
		y = Predecessor(temp);
		printf("predecessor = %ld\n",y->data);
		if((y->data) != (temp->left->data))
		{	puts("far away");
			parent = y->parent;
				if(parent!=NULL){
					printf("ganpati \n");
			if( (parent->left)!=NULL  &&  parent->left->data == y->data){
			left = 1;
			}
			else{
				printf("parent->right = %ld, y= %ld\n",parent->right->data,y->data);
			right = 1;
			}
	}
		}
		
	else{
		printf("attached \n");
		parent = y;
		left = 1;
		}
		x = y->left;
		color = y->black;
		
		if((y->data) != (temp->left->data)){

			transplant(root,y,y->left);
			
			y->left = temp->left;
			
			y->left->parent = y;
		}

		transplant(root,temp,y);

		y->right = temp->right;
				
		y->right->parent = y;

		y->black = temp->black;

		
		free(temp);
	}


	//only if deleted node color is black and if x is null then node has no children hence all rb property remain as such

	if(color == 1){
		puts("kamina");
		if(x==NULL){
		puts("qw");
		x = (node *)malloc(sizeof(node));
		x->left = NULL;
		x->right = NULL;
		x->count = 0;
		x->parent = parent;
		x->black = 1;
		x->data = -1;
		if(parent!=NULL){
	if(left){
		puts("left");
			parent->left = x;
		}
		else{
			puts("right");
			parent->right = x;
		}
	}
		puts("Black");
	}
	printf("x->parent = %ld \n",x->parent->data);
	printf("x = %ld\n",x->data);
	correctDelete(root,x);
	}
	return 0;
}

void correctDelete(node **root,node *x){

	node *sibling,*y,*q,*temp =NULL;
		printf("inside correctDelete = x = %ld\n",x->data );
		if(x->data == -1){
			printf("Here i am \n");
			temp = x;
		}
	while((x->parent)!= NULL && (x->black)==1){
			// if node is left of parent
		if( (x->parent->left !=NULL) && (x->data == x->parent->left->data) ){
			//puts("case 1");
			sibling = x->parent->right;
			//case 1 sibling red
			if( (sibling!=NULL) && (sibling->black) == 0){

				sibling->black = 1;

				x->parent->black = 0;

				leftRotate(root,x->parent);

				sibling = x->parent->right;
			}
			//case 2 both left and right of sibling are black
			if((sibling->left ==NULL || sibling->left->black==1) && ( sibling->right == NULL||sibling->right->black==1) ){
				//puts("case 2");
				sibling->black= 0;
				
				x = x->parent;
			}
			// case 3 sibling is black
			// if its left child is red
			else {
				//puts("case 3");
				if ( (sibling->right==NULL) || sibling->right->black == 1)
			{
				// make sibling left child black and itself red
				if( (sibling->left)!=NULL)
				sibling->left->black = 1;

				sibling->black = 0;

				rightRotate(root,sibling);
			}
			//case 4 sibling right child red

			sibling->black = x->parent->black;
			x->parent->black = 1;
			if((sibling->right)!=NULL)
			sibling->right->black =1;

			leftRotate(root,x->parent);

			break;
		}
	}

			//if node is right of parent
		else{
			puts("else");
			printf("x = %ld \n",x->data);
			sibling = x->parent->left;
			printf("parent = %ld\n",x->parent->data);
			printf("sibling = %ld \n",x->parent->left->data);
			//case 1 sibling red
			if( (sibling!=NULL) && (sibling->black) == 0){
				//puts("case 11");
				sibling->black = 1;

				x->parent->black = 0;

				rightRotate(root,x->parent);

				sibling = x->parent->left;
			}
			//case 2 both left and right of sibling are black
			if((sibling->left == NULL || sibling->left->black==1) && ( sibling->right == NULL||sibling->right->black==1)){
				//puts("case 12");
				sibling->black= 0;
				
				x = x->parent;
			}
			// case 3 sibling is black
			// if its left child is red
			else {
				//puts("case 13");
				if ( (sibling->left==NULL) || sibling->left->black == 1)
			{
				// make sibling right child black and itself red
				sibling->right->black = 1;

				sibling->black = 0;

				leftRotate(root,sibling);
			}
			//case 4 sibling right child red
			//puts("case 14");
			sibling->black = x->parent->black;
			x->parent->black = 1;
			if((sibling->left)!=NULL)
			sibling->left->black =1;

			rightRotate(root,x->parent);
			
			break;
		}

		}
	}

	x->black = 1;

	if(temp!=NULL){

		if(temp->parent == NULL){
			free(temp);
		}
		else{
	if( ((temp->parent->left)!=NULL) && (temp->parent->left->data == temp->data)){
		temp->parent->left = NULL;
		free(temp);
		//puts("Mummy");
	}
	else{
		temp->parent->right = NULL;
		//puts("Papa");
		free(temp);
	}
}
	}
}

void leftRotate(node **root,node *x){
	node *y = x->right;
	x->right = y->left;
	if((y->left)!=NULL)
		y->left->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL){
		*root = y;
	} 
	else if(x->parent->left !=NULL && x->data == x->parent->left->data){
			x->parent->left = y;
	}
	else{
		x->parent->right = y;
	}

	y->left = x;
	if(x->parent !=NULL)
	x->parent = y;
}

void rightRotate(node **root,node *x){
	node *y = x->left;
	x->left = y->right;
	if((y->right)!=NULL)
		y->right->parent = x;
	y->parent = x->parent;
	if(x->parent == NULL){
		*root = y;
	} 
	else if(x->parent->right!=NULL && x->data == x->parent->right->data){
			x->parent->right = y;
	}
	else{
		x->parent->left = y;
	}

	y->right = x;
	if(x->parent !=NULL)
	x->parent = y;
}

void transplant(node **root,node *u,node *v){
	if(u->parent == NULL){
		*root  = v;
	}
	else{
		if(u->parent->data >= u->data){
			
			u->parent->left = v;

		}
		else{
		
			u->parent->right = v;
		}
	}
	if(v!= NULL){
		
		v->parent = u->parent;
	}
}



node * Predecessor(node *root){
	node *temp,*p;
	temp = root->left;

if(temp!=NULL){
printf("temp = %ld\n",temp->data);
while(temp->right!=NULL){
	
	temp = temp->right;
	printf("temp = %ld\n",temp->data);

}

return temp;
}

else{

	p = root->parent;

	while(p!=NULL && root->data == p->right->data){
		
		root = p;
		p = p->parent;
	}
}

return p;
}
