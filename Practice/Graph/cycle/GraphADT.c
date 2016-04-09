#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

struct Vertex *AdjacencyList;
struct Vertex *TransposeList;
int *pi;
int vertices;
int *biColor;

void createGraph(int verticesCount){
vertices = verticesCount;
int i;
AdjacencyList = (struct Vertex *)malloc(sizeof(struct Vertex)*verticesCount);
pi = (int *)malloc(vertices * sizeof(int));
biColor = (int *)malloc(sizeof(vertices));
for(i=0;i<vertices;i++){
	AdjacencyList[i].color = RED;
	AdjacencyList[i].Node = NULL;
	AdjacencyList[i].v = i;
	AdjacencyList[i].discoverT = -1 ;
	AdjacencyList[i].finishT= -1 ;
	AdjacencyList[i].child = 0;
	AdjacencyList[i].bf = 0;
}
}


void Transpose(){
	int i;
	struct node* adj;
	struct node *temp;
	TransposeList = (struct Vertex *)malloc(sizeof(struct Vertex)*vertices);
	for(i=0;i<vertices;i++){
		TransposeList[i].color = RED;
		TransposeList[i].Node = NULL;
		TransposeList[i].v = i;
		TransposeList[i].discoverT = -1 ;
		TransposeList[i].finishT= -1 ;
	}
	for(i=0;i<vertices;i++){
		adj = AdjacencyList[i].Node;
		while(adj!=NULL){
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = i;
	temp->weight = -1;
	temp->next = TransposeList[adj->vertex].Node;
	TransposeList[adj->vertex].Node = temp;
		adj = adj->next;
		}
	}
}
void flushGraph(){
	int i;
	for(i=0;i<vertices;i++){
	AdjacencyList[i].color = RED;
	AdjacencyList[i].discoverT = -1 ;
	AdjacencyList[i].finishT= -1 ;
	pi[i]=-1;
}
}
struct node *adjacentNode(int vertex){
	
	return AdjacencyList[vertex].Node;
}

void addUEdge(int vertex1, int vertex2){
	struct node *temp;
	// vertex1 to vertex2
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex2;
	temp->weight = -1;
	temp->next = AdjacencyList[vertex1].Node;
	AdjacencyList[vertex1].Node = temp;
	AdjacencyList[vertex1].degree +=1;

	//vertex2 to vertex1
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex1;
	temp->weight = -1;
	temp->next = AdjacencyList[vertex2].Node;
	AdjacencyList[vertex2].Node = temp;

}


void addDEdge(int vertex1, int vertex2){
	struct node *temp;
	// vertex1 to vertex2
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex2;
	temp->weight = -1;
	temp->next = AdjacencyList[vertex1].Node;
	AdjacencyList[vertex1].Node = temp;
}



void PrintAdjacent(int n){
	struct node * temp;
	temp = TransposeList[n].Node;
	while(temp!=NULL){
		printf("%d-> ",temp->vertex);
		temp = temp->next;
	}
}

