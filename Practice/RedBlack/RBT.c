#include <stdlib.h>
#include <stdio.h>

typedef struct node{
	long int data;
	long int count;
	short int black;
	struct node *left;
	struct node *right;
	struct node *parent;
	long int red;
}node;



int insert(node **root,node *z,node *nil);
node * newNode(long int data,node *nil);

void RepairTree(node **root,node *child,node *nil);

void leftRotate(node **root,node *x,node *nil);
void rightRotate(node **root,node *x,node *nil);

void search(node **root,long int data,node *nil);

void transplant(node **root,node *u,node *v,node *nil);
long int delete(node **root,long int data,node *nil);
void correctDelete(node **root,node *child,node *nil);
node * Predecessor(node *root,node *nil);


long int doubleRed(node *root);

long int Rank(long int data,node *root,node *nil);

void Inorder(node *tree,node *root,node * nil);

long int FindRank(long int k, node *root, node *nil);
long int RedRank(long int data,node *root,node *nil);

int main (void)
{

node *nil;
nil = (node *)malloc(sizeof(node));
nil->data = -1;
nil->left = NULL;
nil->right = NULL;
nil->black =1;
nil->parent = NULL;
nil->count = 0;
nil->red = 0;

  node *root = nil;
  (root)->parent = nil;
  long int data, check,testcase,rank,element;
  int status;
  node *temp;
  printf ("Enter 0 to search and 1 for insert and 2 for delete 3 for rank 4 for find rank 5 for red rank\n");
  scanf("%ld",&testcase);
  while (testcase >0)
    {
      scanf ("%ld %ld", &check, &data);
      switch (check)
	{
	case 0:
	  search (&root, data,nil);
	  break;

	case 1:
		temp = newNode(data,nil);
	  status = insert (&root,temp,nil);
	  if (status == 0)
	    printf ("Inserted\n");
	  break;
	

	case 2:
	  status = delete (&root, data,nil);
	  if (status != 0)
	    printf ("element not exists\n");
	else{
		printf("Deleted\n");
	}
	  break;

	  case 3:
	  	rank = Rank(data,root,nil);
	  	printf("Rank is = %ld\n",rank);
	  	break;

	  case 4:
	  element = FindRank(data, root, nil);
	  if(element == 0)
	  {
	  	printf("Element with rank %ld not exists\n",data);
	  }
	  else
	  {
	  printf("Element with rank %ld is = %ld\n",data,element);
	}
	  break;

	   case 5:
	  	rank = RedRank(data,root,nil);
	  	printf("Red Rank is = %ld\n",rank);
	  	break;

	  	case 9:
	  	Inorder(root,root,nil);
	  	break;
	default:
	  break;
	}
	testcase --;
    }

Inorder(root,root,nil);
printf("total count = %ld\n",root->count);

}

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
	temp->red =1;
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
			child->red = child->red +1;
			parent = child;
			if(z->data <= child->data){
				child = child->left;
			}
			else{
				child = child->right;
			}
		}
		// node z to br inserted
		z->parent = parent;
		if(parent == nil){
			*root = z;
			(*root)->red  = (*root)->red-1;
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

		node *parent, *grandParent, *uncle,*up;
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
					parent->red = parent->red -1;
					uncle->red = uncle->red -1;
					up = grandParent;
					while(up!=nil){
						up->red  = up->red -1;
						up = up->parent;
					}
				}
				else{ 
				if(child == parent->right){ // case 2 uncle is black if child lies right to parent convert it to case 3
					child = parent;
					leftRotate(root,child,nil);
					parent = child->parent;
					grandParent = parent->parent;
				}
				parent->black = 1;    //case 3 uncle is black 
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
					parent->red = parent->red -1;
					uncle->red = uncle->red -1;
					up = grandParent;
					while(up!=nil){
						up->red  = up->red -1;
						up = up->parent;
					}
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

void Inorder(node *tree,node *root,node * nil){
		if(root == nil){
			return;
		}
		Inorder(tree,root->left,nil);

		printf("<data = %ld,color = %d,rank = %ld,red count = %ld>\n",root->data,root->black,Rank(root->data,tree,nil),root->red);

		Inorder(tree,root->right,nil);

}




// // Deletion 

long int delete(node **root,long int data,node *nil){

	node *predecessor,*z,*y,*x,*up,*down;

	long int l,r;

	short int color;

	int flag = 0;

//search for node to be deleted
	z = *root;

	while(z!=nil){
		//searching for node to be deleted
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
	
	y = z;
	// for holding the node to be deleted and x stores child of the node which replaces the node to be deleted

	color = y->black;

	if(z->left == nil){
			
		x = z->right; // x replaces y
		transplant(root,z,z->right,nil);
		up = z;
			while(up!=nil){
				up->count = up->count -1;
				if(color==0)
					up->red = up->red -1;
				up = up->parent;
			}
		free(z);
	}

	else if(z->right == nil){
			up = z;
		x = z->left;
			transplant(root,z,z->left,nil);
			while(up!=nil){
				up->count = up->count - 1;
				if(color==0)
					up->red = up->red -1;
				up = up->parent;
			}
		free(z);
	}
	else{
		y = Predecessor(z->left,nil);
		color = y->black;
		x = y->left;
		//printf("y->parent = %ld node = %ld , left = %ld, right = %ld\n",y->parent->data,temp->data,temp->left->data,temp->right->data);
		
		if(y->parent == z ){
			x->parent = y;
			flag =1;
		}
			else{
				down = y->left;
			transplant(root,y,y->left,nil);
			y->left = z->left;
			y->left->parent = y;
		}
		y->count = z->count;
		y->red = z->red;
		transplant(root,z,y,nil);
		y->right = z->right;
		y->right->parent = y;
		y->black = z->black;
		
		if(flag){
			up = y->parent;
			while(up!=nil){
				up->count = up->count - 1;
				if(color == 0){
					up->red =  up->red -1;
				}
				up = up->parent;
			}
		}
		else{
				up = down->parent;
			while(up!=nil){
				up->count = up->count - 1;
				if(color==0){
					up->red = up->red - 1;
				}
				up = up->parent;
			}
		}
		free(z);
	}
	//only if deleted node color is black 
	if(color == 1){
		correctDelete(root,x,nil);
	}

	return 0;
}

void correctDelete(node **root,node *x,node *nil){

	node *sibling,*y,*q,*up;

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
				up = sibling;
				while(up!=nil){
					up->red = up->red +1;
					up = up->parent;
				}
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
			sibling->right->red = sibling->right->red -1;
			sibling->red = sibling->red -1;
			leftRotate(root,x->parent,nil);
			up = sibling->parent;
			while(up!=nil){
				up->red = up->red -1;
				up = up->parent;
			}
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
				up = sibling;
				while(up!=nil){
					up->red = up->red +1;
					up = up->parent;
				}
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
			sibling->left->red = sibling->left->red -1;
			sibling->red = sibling->red -1;
			rightRotate(root,x->parent,nil);
			up = sibling->parent;
			while(up!=nil){
				up->red = up->red -1;
				up = up->parent;
			}
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



node * Predecessor(node *root,node *nil){
node *temp,*p = NULL;
temp = root;
while(temp!=nil){
	p = temp;
	temp = temp->right;
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

//Height of x
	x->count = (x->left->count)+(x->right->count)+1;
	//Height of y
	y->count = (y->left->count)+(y->right->count)+1;

	if(x->black==0)
	x->red =   (x->left->red)+(x->right->red)+1;

	else
		x->red =   (x->left->red)+(x->right->red);

	if(y->black == 0)
		y->red = (y->left->red)+(y->right->red)+1;
	
	else
		y->red = (y->left->red)+(y->right->red);

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
	//Height of x
	x->count = (x->left->count)+(x->right->count)+1;
	//Height of y
	y->count = (y->left->count)+(y->right->count)+1;

	if(x->black==0)
	x->red =   (x->left->red)+(x->right->red)+1;

	else
		x->red =   (x->left->red)+(x->right->red);

	if(y->black == 0)
		y->red = (y->left->red)+(y->right->red)+1;
	
	else
		y->red = (y->left->red)+(y->right->red);
	
	
}



//Rank of an element

long int Rank(long int data,node *root,node *nil){

if(root == nil){
	return 1;
}
if(data == root->data){
	return (1+(root->right->count));
}
else if(data > root->data){
	return(Rank(data,root->right,nil));
}
else{
	return(1+(root->right->count)+Rank(data,root->left,nil));
}
}


//Red Rank of an element

long int RedRank(long int data,node *root,node *nil){

if(root == nil){
	return 1;
}
if(data == root->data){
	return (1+(root->right->red));
}
else if(data > root->data){
	return(RedRank(data,root->right,nil));
}
else{
	if(root->black == 0)
	return(1+(root->right->red)+RedRank(data,root->left,nil));
else
	return((root->right->red)+RedRank(data,root->left,nil));
}
}




//Element with a given rank

long int FindRank(long int k, node *root, node *nil){
	if(root==nil){
		return 0;
	}
	if(k == (1+(root->right->count))){
		return	root->data;
	}
	else if(k > root->right->count +1){
		return FindRank(k-(root->right->count)-1,root->left,nil);	
	}
	else{
		return FindRank(k,root->right,nil);
	}
} 