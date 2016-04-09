typedef struct node{
	long int data;
	long int count;
	short int black;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;



int insert(node **root,node *z,node *nil);
node * newNode(long int data,node *nil);

void RepairTree(node **root,node *child,node *nil);

void ZigZig(node **,node *z,node *y,node *x);
void ZigZag(node **,node *z,node *y,node *x);
void leftRotate(node **root,node *x,node *nil);
void rightRotate(node **root,node *x,node *nil);

void search(node **root,long int data,node *nil);

void transplant(node **root,node *u,node *v,node *nil);
long int delete(node **root,long int data,node *nil);
void correctDelete(node **root,node *child,node *nil);
//node * sucessor(node *root,node *nil);
node * Predecessor(node *root,node *nil);


long int doubleRed(node *root);

long int Rank(long int data,node *root,node *nil);

void Inorder(node *tree,node *root,node * nil);

long int FindRank(long int k, node *root, node *nil);