#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct StackNode{
	int value;
	struct StackNode *next;
};
struct StackNode *top = NULL;

extern struct Vertex *AdjacencyList;
extern int *pi;
extern int vertices;

void DFS();
void dfs(int current,int previous);
int CycleFlag = 0;
int time;
void DFS(){
	int i;
	time = 0;
	for(i = 0; i<vertices;i++){
		if(AdjacencyList[i].color==RED){
			pi[i] = i;
			dfs(i,i);
		}
	}
printf("\nPrinting pi\n");
	for(i = 0; i<vertices;i++){
		printf("%d-> ",pi[i]);
	}
}


void dfs(int current,int previous){
	struct node* adj;
	time = time +1;
	AdjacencyList[current].color = YELLOW;
	AdjacencyList[current].discoverT = time;
	adj = AdjacencyList[current].Node;
	while(adj!=NULL){
		if(AdjacencyList[adj->vertex].color == RED){
				pi[adj->vertex] = current;
				dfs(adj->vertex,current);		
		}
		adj = adj->next;
	}
	AdjacencyList[current].color = BLUE;
	time = time +1;
	AdjacencyList[current].finishT = time;
}

