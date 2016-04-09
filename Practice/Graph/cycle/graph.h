#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH

#define GRAPH

#define RED 1
#define YELLOW 2
#define BLUE 3
#define WHITE 4
#define BLACK 5

struct node{
	int vertex;
	int weight;
	struct node *next;
};

struct Vertex{
	int color;
	int v;
	struct node *Node;
	int discoverT;
	int finishT;
	int degree;
	int bf;
	int child;
	int marked;
};
void createGraph(int verticesCount);
struct node *adjacentNode(int vertex);
//void addUEdge(int vertex1, int vertex2, int weight);
void addUEdge(int vertex1, int vertex2);
void addDEdge(int vertex1, int vertex2);
//void addDEdge(int vertex1, int vertex2,int weight);
void PrintAdjacent(int n);
int cycleCheck();
void flushGraph();
void Topological();
void ConnectedComponent();
void Bipartite();
void Transpose();
void StronglyConnected();
void childCount();

#endif