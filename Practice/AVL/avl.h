typedef struct node{
	long int data;
	long int height;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;

node * newNode(long int data);
long int insert(node **root,long int data);
void ZigZig(node **,node *z,node *y,node *x);
void ZigZag(node **,node *z,node *y,node *x);
void Inorder(node *root);
void transplant(node **root,node *u,node *v);
node * Predecessor(node *root);
long int delete(node **root,long int data);
void search(node **root,long int data);