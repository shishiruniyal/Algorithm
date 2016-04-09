#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

void Prims(int source);
void MinimumSpanning();

extern struct Vertex *AdjacencyList;
extern int *pi;
extern int vertices;
extern int heapLength;

void Prims(int source){
	struct node* adjacent;
	int min;
	CreateHeap(vertices);

	insert(0,source);
	AdjacencyList[source].pri = 0;
	min = extractMin();
	AdjacencyList[min].color = BLUE;
	pi[source] = source;
	while(min!=-1){
	adjacent = AdjacencyList[min].Node;
	while(adjacent!=NULL){

		if(AdjacencyList[adjacent->vertex].color == RED){
			AdjacencyList[adjacent->vertex].pri = adjacent->weight;
			AdjacencyList[adjacent->vertex].color = YELLOW;
			pi[adjacent->vertex] = min;
			insert(AdjacencyList[adjacent->vertex].pri,adjacent->vertex);
		}
		else if(AdjacencyList[adjacent->vertex].color == YELLOW){
			//printf("Here for %d\n,weight = %d,",adjacent->vertex,adjacent->weight);
			if(AdjacencyList[adjacent->vertex].pri > adjacent->weight)
			{
				AdjacencyList[adjacent->vertex].pri = adjacent->weight;
				decreaseKey(AdjacencyList[adjacent->vertex].HeapPoint , AdjacencyList[adjacent->vertex].pri);
				pi[adjacent->vertex] = min;
			}
		}
		adjacent = adjacent->next;
	}
	min = extractMin();	
	if(min!=-1)
	AdjacencyList[min].color = BLUE;
	//printf("Minimum = %d\n",min);
}

}


void MinimumSpanning(){
	int i,total=0;
	for(i=0;i<vertices;i++){
		printf("(%d,%d)\n",pi[i],i);
		total += AdjacencyList[i].pri;
	}
	printf("Total weight of the tree is %d \n",total);
}