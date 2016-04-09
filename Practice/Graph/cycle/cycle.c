#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct StackNode{
	int value;
	struct StackNode *next;
};
struct StackNode *top = NULL;
struct topoList{
	int value;
	struct topoList *next;
};
extern struct Vertex *AdjacencyList;
extern struct Vertex *TransposeList;
extern int *pi;
extern int vertices;
extern int *biColor;
int cycleCheck();
void DFS();
void dfs(int current,int previous);
int CycleFlag = 0;
int time;
struct topoList *head;
int ComponentCount;
int bipartFlag;
int headFlag;




// void StronglyConnected(){
// 	Topological();
// 	struct topoList * temp;
// 	temp = head;
// 	flushGraph();
// 	ComponentCount = 0;
// 	while(temp!=NULL){
// 		if(TransposeList[temp->value].color == RED){
// 			ComponentCount ++;
// 			dfs(TransposeList,temp->value,temp->value);
// 		}
// 		temp = temp->next;
// 	}
// 	printf("Strongly Connected Component count is %d \n",ComponentCount);
// }


// void ConnectedComponent(){
// 	ComponentCount = 0;
// 	DFS();
// 	printf("Connected component count = %d \n",ComponentCount);
// }

// void Bipartite(){
// int i;
// for(i=0;i<vertices;i++){
// 	biColor[i]=0;
// }
// bipartFlag = 1;
// DFS();
// if(bipartFlag == 0){
// 	printf("This is not a bipartite graph \n");
// }
// else{
// 	printf("We have a bipartite graph here\n");
// 	printf("SET1");
// 	for(i =0; i<vertices;i++){
// 		if(biColor[i]==WHITE){
// 			printf(" %d ",i);
// 		}
// 	}

// 	printf("\nSET2");
// 	for(i =0; i<vertices;i++){
// 		if(biColor[i] == BLACK){
// 			printf(" %d ",i);
// 		}
// 	}
// 	printf("\n");
// }
// }


// int cycleCheck(){
// 	CycleFlag = 0;
// 	DFS();
// 	if(CycleFlag){
// 		return 1;
// 	}	
// }

// void Topological(){
// 	struct topoList *temp;
// 	head = NULL;
// 	headFlag = 1;
// 	DFS();
// 	headFlag = 0;
// 	// temp = head;
// 	// printf("Topological sort is \n");
// 	// while(temp!=NULL){
// 	// 	printf(" %d -> ",temp->value);
// 	// 	temp = temp->next;
// 	// }
// 	// printf("\n");
// }



void DFS(){
	int i;
	time = 0;
	for(i = 0; i<vertices;i++){
		if(AdjacencyList[i].color==RED){
			pi[i] = i;
			dfs(i,i);
		}
	}
// printf("\nPrinting pi\n");
// 	for(i = 0; i<vertices;i++){
// 		printf("%d-> ",pi[i]);
// 	}
}

void dfs(int current,int previous){
	struct node* adj;
	struct topoList* temp;
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

void childCount(){
		DFS();
 struct node *temp;
	int i,max =0;
	for(i=0;i<vertices;i++){
	 	AdjacencyList[i].child = ((((AdjacencyList[i].finishT)-1)-AdjacencyList[i].discoverT)/2)+1;
	}
	for(i=0;i<vertices;i++){
		temp = AdjacencyList[i].Node;
		max = 0;
		while(temp!=NULL){

		if( AdjacencyList[temp->vertex].child < AdjacencyList[i].child  && max < AdjacencyList[temp->vertex].child){
			max = AdjacencyList[temp->vertex].child;
			}
			temp = temp->next;
		}
		if(max < vertices-(AdjacencyList[i].child)){
			max = vertices-(AdjacencyList[i].child);
		}
		AdjacencyList[i].bf = max;
	}

	// for(i = 0;i<vertices;i++){
	// 	printf("Vertex %d,	finish = %d,	departure = %d,	child = %d bf= %d \n",i,AdjacencyList[i].finishT,AdjacencyList[i].discoverT,AdjacencyList[i].child,AdjacencyList[i].bf);
	// }
}

void Answer(){
	int i,min=100000,vertee;
	for(i=0;i<vertices;i++){
		if(min > AdjacencyList[i].bf){
			min = AdjacencyList[i].bf;
			vertee=i;
		}
	}
	printf("%d,%d\n",min,vertee+1);

}

