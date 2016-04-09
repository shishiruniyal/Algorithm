#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH

#define GRAPH

#define RED 1
#define YELLOW 2
#define BLUE 3


struct node{
	int vertex;
	int weight;
	struct node *next;
};

struct Vertex{
	int color;
	int v;
	int HeapPoint;
	struct node *Node;
	int pri;
};
void createGraph(int verticesCount);
struct node *adjacentNode(int vertex);
//void addUEdge(int vertex1, int vertex2, int weight);
void addUEdge(int vertex1, int vertex2);
void addDEdge(int vertex1, int vertex2);
//void addDEdge(int vertex1, int vertex2,int weight);
void PrintAdjacent(int n);

#endif