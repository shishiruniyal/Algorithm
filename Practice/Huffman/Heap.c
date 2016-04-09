#include<stdio.h>
#include<stdlib.h>
#include "huff.h"

struct TreeNode *Heap;
int HeapCount;

void BuildHeap(struct node* List,int count){
	int i;
HeapCount = count;
Heap = (struct TreeNode*)malloc(sizeof(struct TreeNode)*HeapCount);
for(i=0;i<HeapCount;i++){
	Heap[i].frequency = List->frequency;
	Heap[i].c = List->c;
	Heap[i].left = NULL;
	Heap[i].right = NULL;
	List = List->next;
}
i = HeapCount/2;
while(i>=0){
BottomUp(i);
i--;
}
}

void BottomUp(int i){
	int parent = i/2;
	while(i>=0 && Heap[parent].frequency > Heap[i].frequency){
		int tempF;
		char tempch;
		struct TreeNode* temp;

		tempF = Heap[parent].frequency;
		Heap[parent].frequency = Heap[i].frequency;
		Heap[i].frequency = tempF;

		tempch = Heap[parent].c;
		Heap[parent].c = Heap[i].c;
		Heap[i].c = tempch;
		temp = Heap[parent].left;
		Heap[parent].left = Heap[i].left;
		Heap[i].left = temp;

		temp = Heap[parent].right;
		Heap[parent].right = Heap[i].right;
		Heap[i].right = temp;

		i = parent;
		parent = parent/2;
	}
}