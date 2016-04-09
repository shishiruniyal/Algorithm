#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"

struct Vertex *AdjacencyList;
int *pi;
int vertices;

void createGraph(int verticesCount){
	vertices = verticesCount;
int i;
AdjacencyList = (struct Vertex *)malloc(sizeof(struct Vertex)*verticesCount);
pi = (int *)malloc(vertices * sizeof(int));

for(i=0;i<vertices;i++){
	AdjacencyList[i].color = RED;
	AdjacencyList[i].Node = NULL;
	AdjacencyList[i].v = i;
	AdjacencyList[i].pri =INT_MAX ;
	pi[i]=-1;
}
}

struct node *adjacentNode(int vertex){
	
	return AdjacencyList[vertex].Node;
}

void addUEdge(int vertex1, int vertex2 ,int weight){
	struct node *temp;
	// vertex1 to vertex2
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex2;
	temp->weight = weight;
	temp->next = AdjacencyList[vertex1].Node;
	AdjacencyList[vertex1].Node = temp;


	//vertex2 to vertex1
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex1;
	temp->weight = weight;
	temp->next = AdjacencyList[vertex2].Node;
	AdjacencyList[vertex2].Node = temp;

}


void addDEdge(int vertex1, int vertex2, int weight){
	struct node *temp;
	// vertex1 to vertex2
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex2;
	temp->weight = weight;
	temp->next = AdjacencyList[vertex1].Node;
	AdjacencyList[vertex1].Node = temp;
}



void PrintAdjacent(int n){
	struct node * temp;
	temp = AdjacencyList[n].Node;
	while(temp!=NULL){
		printf("%d-> ",temp->vertex);
		temp = temp->next;
	}
}