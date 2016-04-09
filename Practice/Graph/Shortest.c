#include <stdio.h>
#include <stdlib.h>

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
	struct node *Node;
};
struct queuNode{
	struct Vertex *v;
	struct queuNode *next;
};


void createGraph(int verticesCount);
struct node *adjacentNode(int vertex);
void addUEdge(int vertex1, int vertex2);
void enqueue(struct Vertex *v);
struct Vertex *dequeue();
void bfs(int s);


struct Vertex *AdjacencyList;
int *di;
int vertices;
struct queuNode *Front =NULL, *Rear=NULL;

void createGraph(int verticesCount){
	vertices = verticesCount;
int i;
AdjacencyList = (struct Vertex *)malloc(sizeof(struct Vertex)*verticesCount);
di = (int *)malloc(vertices * sizeof(int));
for(i=0;i<vertices;i++){
	AdjacencyList[i].color = RED;
	AdjacencyList[i].Node = NULL;
	AdjacencyList[i].v = i;
	di[i]=-1;
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
	temp->next = AdjacencyList[vertex1].Node;
	AdjacencyList[vertex1].Node = temp;

	//vertex2 to vertex1
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp){
		printf("malloc failed \n");
		return;
	}
	temp->vertex = vertex1;
	temp->next = AdjacencyList[vertex2].Node;
	AdjacencyList[vertex2].Node = temp;

}



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

void bfs(int s){
	int distance = 0;
	struct node *ad;
	struct Vertex *ver;
	enqueue(AdjacencyList+s);
	di[s]=0;
	while(Front!=NULL){
		ver = dequeue();
		ver->color = BLUE;
		ad = ver->Node;
		while(ad!=NULL){
			if(AdjacencyList[ad->vertex].color == RED)
				{
					enqueue(AdjacencyList+(ad->vertex));
					di[ad->vertex] = di[ver->v]+1;
					AdjacencyList[ad->vertex].color = YELLOW;
				}
			ad = ad->next;
		}
	}
}



int main(){
	int test,i;
	int N;
	int E;
	int s;
	int v1,v2;
	scanf("%d",&test);
	while(test>0){
		scanf("%d",&N);
		scanf("%d",&E);
		createGraph(N);
		while(E>0){
			scanf("%d%d",&v1,&v2);
			addUEdge(v1-1,v2-1);
			E--;
		}
		scanf("%d",&s);
		bfs(s-1);
		for(i=0;i<N;i++){
			if(i!=(s-1)){
				if(di[i]!=-1)
					printf("%d ",di[i]*6);
				else
					printf("%d ",di[i]);
			}
		}
		printf("\n");
		free(AdjacencyList);
		free(di);
		test--;
	}
}