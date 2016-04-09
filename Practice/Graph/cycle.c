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

void push(int value);
int pop();
void DFS();
void dfs();

void push(int value){
	struct StackNode *temp;
	temp = top;
	top = (struct StackNode *)malloc(sizeof(struct StackNode));
	top->value = value;
	top->next = temp;
}

int pop(){
	int value;
	struct StackNode *temp;
	if(top==NULL){
		return -1;
	}
	value = top->value;
	temp = top;
	top = top->next;
	free(temp);
	return value;
}


void DFS(){
	int i;
	//printf("\nPrinting DFS\n");
	for(i = 0; i<vertices;i++){
		if(AdjacencyList[i].color==RED){
			push(i);
			pi[i]=i;
			dfs();
		}
	}

	// printf("\nPrinting pi\n");
	// for(i = 0; i<vertices;i++){
	// 	printf("%d-> ",pi[i]);
	// }
}


void dfs(){
	struct node* adj;
	int temp;
	temp = pop();
	while(temp!=-1){
	AdjacencyList[temp].color = BLUE;
	printf("%d-> ",temp);
	adj = AdjacencyList[temp].Node;
	while(adj!=NULL){
		if( (AdjacencyList[adj->vertex].color != RED) && adj->vertex != temp){
			printf("Cycle Reported");
			break;
		}
		if(AdjacencyList[adj->vertex].color == RED || AdjacencyList[adj->vertex].color == YELLOW){
				push(adj->vertex);
				AdjacencyList[adj->vertex].color = YELLOW;	
				pi[adj->vertex] = temp;
		}
		adj = adj->next;
	}
	temp = pop();
}

}