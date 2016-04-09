#include <stdlib.h>
#include <stdio.h>

#include "graph.h" 

struct queuNode{
	struct Vertex *v;
	struct queuNode *next;
};

struct queuNode *Front =NULL, *Rear=NULL;

extern struct Vertex *AdjacencyList;
extern int *pi;
extern int vertices;


void enqueue(struct Vertex *v);
struct Vertex *dequeue();
void BFS();
void bfs();

void enqueue(struct Vertex *v){
struct queuNode *temp;
temp = (struct queuNode *)malloc(sizeof(struct queuNode));
temp->v = v;
if(Rear == NULL && Front == NULL){
	temp->next = NULL;
	Rear = temp;
	Front = temp;
	return;
}
Rear->next = temp;
Rear = temp;
}

struct Vertex *dequeue(){
	struct Vertex *v = Front->v;
	struct queuNode *temp = Front;
	if(Front==Rear){
		Front = NULL;
		Rear = NULL;
	}
	else{
	Front = Front->next;
	}
	free(temp);
	return v;
}


void BFS(){
	int i;
	struct Vertex *temp;
	printf("\nPrinting BFS\n");
	for(i=0;i<vertices;i++){
		if(AdjacencyList[i].color == RED){
			pi[i]=i;
			enqueue(AdjacencyList+i);
			bfs();
		}
	}
	printf("\nPrinting pi\n");
	for(i = 0; i<vertices;i++){
		printf("%d-> ",pi[i]);
	}

}

void bfs(){
	struct node *ad;
	struct Vertex *ver;
	while(Front!=NULL){
		ver = dequeue();
		printf("%d-> ",ver->v);
		ver->color = BLUE;
		ad = ver->Node;
		while(ad!=NULL){
			if(AdjacencyList[ad->vertex].color == RED)
				{
					enqueue(AdjacencyList+(ad->vertex));
					pi[ad->vertex] = ver->v;
					AdjacencyList[ad->vertex].color = YELLOW;
				}
			ad = ad->next;
		}
	}
}