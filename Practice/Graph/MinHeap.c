#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct HeapNode{
int priority;
int vertexNode;
};

void CreateHeap(int verticesCount);
void insert(int key,int index);
int extractMin();
void decreaseKey(int index,int value);
void topDownHeapify(int index);
void bottomUpHeapify(int index);

int heapLength;
struct HeapNode *Heap;
extern struct Vertex *AdjacencyList;
extern int vertices;

void CreateHeap(int verticesCount){
	heapLength = 0;
	Heap = (struct HeapNode *)malloc(sizeof(struct HeapNode)*verticesCount);
}


void bottomUpHeapify(int index){
	int parent;
	int tempP,tempV;
	if(index == 0){
		return;
	}
	parent = (index -1)/2;
	while(parent >= 0 && index >0){
		if(Heap[index].priority < Heap[parent].priority){
			tempP = Heap[index].priority;
			Heap[index].priority = Heap[parent].priority;
			Heap[parent].priority = tempP;
			tempV = Heap[index].vertexNode;
			Heap[index].vertexNode = Heap[parent].vertexNode;
			Heap[parent].vertexNode = tempV;
			AdjacencyList[Heap[index].vertexNode].HeapPoint = index;
			AdjacencyList[Heap[parent].vertexNode].HeapPoint = parent;
		}
		else{
			break;
		}
		index = parent;
		parent = (parent - 1)/2;
	}

}


void topDownHeapify(int index){
	int parent, left, right, minimum, tempP, tempV;

	parent = index;
	left = 2*parent + 1;
	right = 2*parent + 2;

	while(left < heapLength){
			if(right >= heapLength){
				minimum = left;
			}
			else{
				if(Heap[right].priority < Heap[left].priority){
					minimum = right;
				}
				else{
					minimum = left;
				}
			}
		if(Heap[minimum].priority < Heap[parent].priority){
			tempP = Heap[parent].priority;
			Heap[parent].priority = Heap[minimum].priority;
			Heap[minimum].priority = tempP;

			tempV = Heap[parent].vertexNode;
			Heap[parent].vertexNode = Heap[minimum].vertexNode;
			Heap[minimum].vertexNode = tempV;

			AdjacencyList[Heap[minimum].vertexNode].HeapPoint = minimum;
			AdjacencyList[Heap[parent].vertexNode].HeapPoint = parent;

		parent = minimum;
		left = 2*parent +1;
		right = 2*parent +2;
		}
		else{
			break;
		}
	}
}


void insert(int key,int index){
	int index1;
	//puts("Here");
	//printf("vertices = %d, heapLength = %d\n",vertices,heapLength);
if(heapLength == vertices){
	printf("Heap full\n");
	return;
}
Heap[heapLength].priority = key;
Heap[heapLength].vertexNode = index;
index1 = heapLength;
heapLength++;
AdjacencyList[index].HeapPoint = index1;
bottomUpHeapify(index1);
}

int extractMin(){
int vertex;
if(heapLength==0){
	return -1;
}
vertex = Heap[0].vertexNode;
if(heapLength>1){
Heap[0].priority = Heap[heapLength-1].priority;
Heap[0].vertexNode = Heap[heapLength-1].vertexNode;
AdjacencyList[Heap[0].vertexNode].HeapPoint = 0;
}
heapLength--;
topDownHeapify(0);
return vertex;
}

void decreaseKey(int index,int value){
	if(Heap[index].priority <= value){
		printf("Inappropriate value \n");
		return;
	}
	Heap[index].priority = value;
	bottomUpHeapify(index);
}
