#ifndef STACK
#define STACK

typedef struct node {
	void * data;
	struct node *next;
}NODE;

int push(void * data);
void* peek();
void* pop();

#endif