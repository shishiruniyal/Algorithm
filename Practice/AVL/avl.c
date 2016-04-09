#include "avl.h"
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
	temp->height = 0;
	return temp;
}

//Inserting a node
long int insert(node **root, long int data){
		node *temp;
		node *p =NULL;
		node *x,*y,*z;
		long int flag = 1;
		temp = *root;
		while(temp!=NULL){
			p = temp;
			if(data <= temp->data){
				temp = temp->left;
			}
			else{
				temp = temp->right;
			}
		}

		if(p==NULL){
			*root = newNode(data);
			(*root)->parent = NULL;
			return 0;
		}
		temp = newNode(data);
		temp->parent = p;	

		if(p->data >= data){
			p->left = temp;
		}

		else{
			p->right = temp;
		}

//For checking imbalance
		y = temp;
		while(flag && p!=NULL){
			
			long int l,r;
			if(p->left == NULL){
				l = -1;

				r = p->right->height;
			}
			else if(p->right == NULL){
				r = -1;
				l = p->left->height;
			}

			else{
				l = p->left->height;
				r = p->right->height;
			}
				p->height = l>r?l+1:r+1;
				

			if((l==-1 && r==-1 ) || abs(l-r)<2){
				x = y;
				y = p;
				p = p->parent;
			}

			else{
				z = p;		
				if( (z->left!=NULL && y->left!=NULL && z->left->data == y->data && y->left->data == x->data) || (z->right!=NULL && y->right!=NULL && z->right->data == y->data && y->right->data == x->data) ){
								
					ZigZig(root,z,y,x);
					flag = 0;	
				}
				else{		
					ZigZag(root,z,y,x);
					flag = 0;
				}
			}
		}
		return 0;

}


void ZigZig(node **root,node *z,node *y,node *x){
long int l,r;
y->parent = z->parent;
if(z->parent == NULL){
	*root = y;
}
else{
	if(z->parent->left->data == z->data){
		z->parent->left = y;
	}
	else{
		z->parent->right = y;
	}
}
//zig zig all in right
if((z->right!=NULL && z->right->data == y->data && y->right->data == x->data)){
	z->right = y->left;
	if(y->left!=NULL)
		y->left->parent = z;
	y->left = z;
	z->parent = y;
}
else{
	z->left = y->right;
	if(y->right!=NULL)
		y->right->parent = z;
	y->right = z;
	z->parent = y;
}
if(z->left == NULL && z->right ==NULL){
		l = -1;
		r = -1;
	}
	else if(z->left!=NULL && z->right==NULL){
		l = z->left->height;
		r = -1;
	}
	else if(z->right!=NULL && z->left==NULL){
		r = z->right->height;
		l = -1;
	}
	else{
		l = z->left->height;
		r = z->right->height;
	}
	z->height = l>r?l+1:r+1;
	y->height = (z->height) > (x->height) ? (z->height)+1:(x->height)+1;
}


void ZigZag(node **root,node *z,node *y,node *x){

	long int l,r;

	x->parent = z->parent;
	
	if(z->parent == NULL){	
	*root = x;
	}
else{
	if(z->parent->left->data == z->data){
					
		z->parent->left = x;
	}
	else{
					
		z->parent->right = x;
	}
}
z->parent = x;
y->parent = x;
	//right and then left
		if(z->right!=NULL && z->right->data == y->data){
			z->right = x->left;
			if(z->right !=NULL)
				z->right->parent=z;
			y->left = x->right;
			if(y->left!=NULL)
				y->left->parent=y;
			x->left = z;
			x->right = y;

		}
//left and then right
		else{
						
			z->left = x->right;
			if(z->left!=NULL)
				z->left->parent=z;
			y->right = x->left;
			if(y->right !=NULL)
				y->right->parent=y;
			x->left = y;
			x->right = z;		

		}

//height of z
		if(z->left == NULL){
						

			if(z->right == NULL){
			z->height = 0;
		}
		else{
					
			z->height = z->right->height +1;
		}
		}
		else if(z->right == NULL){
						

			if(z->left == NULL){
							

				z->height = 0;
			}
			else{
							
				z->height = z->left->height +1;
			}
		}

		else{

			z->height = z->left->height > z->right->height ? z->left->height +1 : z->right->height +1;
		}

//height of y
if(y->left == NULL){
			if(y->right == NULL){
			y->height = 0;
		}
		else{
			y->height = y->right->height +1;
		}
		}
		else if(y->right == NULL){
			if(y->left == NULL){
				y->height = 0;
			}
			else{
				y->height = y->left->height +1;
			}
		}
		else{
			y->height = y->left->height > y->right->height ? y->left->height +1 : y->right->height +1;
		}

//height of x
		x->height = x->left->height > x->right->height ? x->left->height +1 : x->right->height +1;

}







//Inorder traversal

void Inorder(node *root){
		if(root == NULL){
			return;
		}
		Inorder(root->left);
		printf("<%ld,%ld> ",root->data,root->height);
		Inorder(root->right);

}

//Deletion
long int delete(node **root,long int data){
	node *temp,*predecessor,*z,*y,*x;
	long int l,r,HeightBefore,HeightAfter;
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
			// checking for deletion case
			if(temp->right==NULL){
				//puts("One");
				z = temp->parent; //for comming back up
				transplant(root,temp,temp->left);
				free(temp);
			}
			else if(temp->left==NULL){
				//puts("two");
				z = temp->parent; //for comming back up
				transplant(root,temp,temp->right);
				free(temp);
			}

			else{
				predecessor = Predecessor(temp);
				if(predecessor->data  == temp->left->data){
					z = predecessor;
				}
				if(predecessor->data != temp->left->data){
					z = predecessor->parent;
					transplant(root,predecessor,predecessor->left);
					predecessor->left = temp->left;
					predecessor->left->parent = predecessor;
				}
				transplant(root,temp,predecessor);
				predecessor->right = temp->right;
				predecessor->right->parent = predecessor;
				if( (predecessor->left)!=NULL && (predecessor->right)!=NULL )
		 predecessor->height = (predecessor->left->height) > (predecessor->right->height) ? (predecessor->left->height)+1 : (predecessor->right->height)+1;
				free(temp);
			}
				while(z!=NULL){
					//printf("z = %ld\n",z->data);
					HeightBefore = z->height;
						if( (z->right==NULL) && (z->left!=NULL) ){
							//puts("Here1");
						r = -1;
						l = z->left->height;	
							}
					else if( (z->left==NULL) &&  (z->right!= NULL)){
						//puts("Here2");
						l = -1;
						r = z->right->height;
					}
					else if(z->left==NULL && z->right==NULL){
						//puts("Here 3");
						l=-1;
						r=-1;
					}
					else{
						//puts("Here 4");
						l = z->left->height;
						r = z->right->height;
					}

						z->height = l>r?l+1:r+1;
						//printf("z height = %ld\n",z->height);
						if( (l==-1 && r==-1) || abs(l-r)<2){
							z = z->parent;
						}
						else{
							long int left=-1,right=-1;
							if(l>=r){
								//try for zig zig
									y = z->left;
									if(y->left != NULL){
										left = y->left->height;
									}
									if(y->right != NULL){
										right = y->right->height;
									}
									if(left>=right){
										x = y->left;
										ZigZig(root,z,y,x);
										HeightAfter = y->height;
										z = y->parent;
									}
									else{
										x = y->right;
										ZigZag(root,z,y,x);
										HeightAfter = x->height;
										z = x->parent;
									}
							}
							else{
								left =-1;
								right =-1;
								y = z->right;
								if(y->left != NULL){
										left = y->left->height;
									}
									if(y->right != NULL){
										right = y->right->height;
									}
								if(right >= left){
										x = y->right;
										ZigZig(root,z,y,x);
										HeightAfter = y->height;
										z = y->parent;
									}
									else{
										x = y->left;
										ZigZag(root,z,y,x);
										HeightAfter = x->height;
										z = x->parent;
									}
							}
							if(HeightBefore==HeightAfter)
								break;
						}

						
				}
				return 0;
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
while(temp->right!=NULL){
	
	temp = temp->right;
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