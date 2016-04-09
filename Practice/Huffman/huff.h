#ifndef e

#define e


struct TreeNode{
	int frequency;
	char c;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct node {
	char c;
	int frequency;
	struct node *next;
};

void BuildHeap(struct node* List,int count);
void BottomUp(int i);

#endif