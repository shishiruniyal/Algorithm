#include<stdlib.h>
#include<stdio.h>

typedef struct node{
int key;
char data[50];
struct node * parent;
struct node * left;
struct node * right;
}Node;

int insert(Node **root,int key,char* data);
char* search(Node *root,int key);
int delete(Node **root,int key);

void transplant(Node **root,Node *u, Node *v);
Node* Predecessor(Node * root);

void InOrder(Node *root);
void PostOrder(Node *root);
void PreOrder(Node *root);
void LevelOrder(Node *root);
void MorrisOrder(Node *root);



void testInser();
void testDelete();
void testSearch();
void testInorder();