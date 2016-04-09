typedef struct node{
	long int data;
	long int count;
	short int black;
	struct node *left;
	struct node *right;
	struct node *parent;
}node;



int insert(node **root,long int data);
node * newNode(long int data);

void RepairTree(node **root,node *child);

void ZigZig(node **,node *z,node *y,node *x);
void ZigZag(node **,node *z,node *y,node *x);
void leftRotate(node **root,node *x);
void rightRotate(node **root,node *x);

void search(node **root,long int data);

void transplant(node **root,node *u,node *v);
long int delete(node **root,long int data);
void correctDelete(node **root,node *child);
node *Predecessor(node *root);


long int doubleRed(node *root);