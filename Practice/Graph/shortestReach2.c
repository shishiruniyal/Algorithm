#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

struct HeapNode{
int priority;
int vertexNode;
};

void createGraph(int verticesCount);
struct node *adjacentNode(int vertex);
void addUEdge(int vertex1, int vertex2, int weight);
void CreateHeap(int verticesCount);
void insert(int key,int index);
int extractMin();
void decreaseKey(int index,int value);
void topDownHeapify(int index);
void bottomUpHeapify(int index);
void Dijkstra(int source);
void PrintAdjacent(int n);




struct Vertex *AdjacencyList;
int *pi;
int vertices;
int heapLength;
struct HeapNode *Heap;


void createGraph(int verticesCount){
	vertices = verticesCount;
int i;
AdjacencyList = (struct Vertex *)malloc(sizeof(struct Vertex)*verticesCount);

for(i=0;i<vertices;i++){
	AdjacencyList[i].color = RED;
	AdjacencyList[i].Node = NULL;
	AdjacencyList[i].v = i;
	AdjacencyList[i].pri =INT_MAX ;
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


void CreateHeap(int verticesCount){
	heapLength = 0;
	Heap = (struct HeapNode *)malloc(sizeof(struct HeapNode)*verticesCount);
}

void PrintAdjacent(int n){
	struct node * temp;
	temp = AdjacencyList[n].Node;
	while(temp!=NULL){
		printf("%d-> ",temp->vertex);
		temp = temp->next;
	}
}
void bottomUpHeapify(int index){
	int parent;
	int tempP,tempV;
	if(index == 0){
		return;
	}
	parent = (index -1)/2;
	while(parent >= 0 && index >0){
		if(Heap[index].priority < Heap[parent].priority){
			tempP = Heap[index].priority;
			Heap[index].priority = Heap[parent].priority;
			Heap[parent].priority = tempP;
			tempV = Heap[index].vertexNode;
			Heap[index].vertexNode = Heap[parent].vertexNode;
			Heap[parent].vertexNode = tempV;
			AdjacencyList[Heap[index].vertexNode].HeapPoint = index;
			AdjacencyList[Heap[parent].vertexNode].HeapPoint = parent;
		}
		else{
			break;
		}
		index = parent;
		parent = (parent - 1)/2;
	}

}


void topDownHeapify(int index){
	int parent, left, right, minimum, tempP, tempV;

	parent = index;
	left = 2*parent + 1;
	right = 2*parent + 2;

	while(left < heapLength){
			if(right >= heapLength){
				minimum = left;
			}
			else{
				if(Heap[right].priority < Heap[left].priority){
					minimum = right;
				}
				else{
					minimum = left;
				}
			}
		if(Heap[minimum].priority < Heap[parent].priority){
			tempP = Heap[parent].priority;
			Heap[parent].priority = Heap[minimum].priority;
			Heap[minimum].priority = tempP;

			tempV = Heap[parent].vertexNode;
			Heap[parent].vertexNode = Heap[minimum].vertexNode;
			Heap[minimum].vertexNode = tempV;

			AdjacencyList[Heap[minimum].vertexNode].HeapPoint = minimum;
			AdjacencyList[Heap[parent].vertexNode].HeapPoint = parent;

		parent = minimum;
		left = 2*parent +1;
		right = 2*parent +2;
		}
		else{
			break;
		}
	}
}


void insert(int key,int index){
	int index1;
	//puts("Here");
	//printf("vertices = %d, heapLength = %d\n",vertices,heapLength);
if(heapLength == vertices){
	printf("Heap full\n");
	return;
}
Heap[heapLength].priority = key;
Heap[heapLength].vertexNode = index;
index1 = heapLength;
heapLength++;
AdjacencyList[index].HeapPoint = index1;
bottomUpHeapify(index1);
}

int extractMin(){
int vertex;
if(heapLength==0){
	return -1;
}
vertex = Heap[0].vertexNode;
if(heapLength>1){
Heap[0].priority = Heap[heapLength-1].priority;
Heap[0].vertexNode = Heap[heapLength-1].vertexNode;
AdjacencyList[Heap[0].vertexNode].HeapPoint = 0;
}
heapLength--;
topDownHeapify(0);
return vertex;
}

void decreaseKey(int index,int value){
	if(Heap[index].priority <= value){
		printf("Inappropriate value \n");
		return;
	}
	Heap[index].priority = value;
	bottomUpHeapify(index);
}

void Dijkstra(int source){
	struct node* adjacent;
	int min;
	CreateHeap(vertices);

	insert(0,source);
	AdjacencyList[source].pri = 0;
	min = extractMin();
	AdjacencyList[min].color = BLUE;
	while(min!=-1){
	adjacent = AdjacencyList[min].Node;
	while(adjacent!=NULL){

		if(AdjacencyList[adjacent->vertex].color == RED){
			AdjacencyList[adjacent->vertex].pri = AdjacencyList[min].pri + adjacent->weight;
			AdjacencyList[adjacent->vertex].color = YELLOW;
			insert(AdjacencyList[adjacent->vertex].pri,adjacent->vertex);
		}
		else if(AdjacencyList[adjacent->vertex].color == YELLOW){
			//printf("Here for %d\n,weight = %d,",adjacent->vertex,adjacent->weight);
			if(AdjacencyList[adjacent->vertex].pri > (AdjacencyList[min].pri + adjacent->weight))
			{
				AdjacencyList[adjacent->vertex].pri = AdjacencyList[min].pri + adjacent->weight;
				decreaseKey(AdjacencyList[adjacent->vertex].HeapPoint,AdjacencyList[adjacent->vertex].pri);
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

void PrintPath(int Destination){

	if(Destination >= vertices){
		printf("Destination does not exists\n");
		return;
	}
	if(pi[Destination]==Destination){
		return;
	}
	else{
		PrintPath(pi[Destination]);
	}
	printf("<%d>-----> ",Destination);
}

int main(void){
	int N,M,i,v1,v2,d,w,s,test;
	scanf("%d",&test);
	while(test>0){
	scanf("%d%d",&N,&M);
	createGraph(N);
	while(M!=0){
		scanf("%d%d%d",&v1,&v2,&w);
		addUEdge(v1-1,v2-1,w);
		M--;
	}
	scanf("%d",&s);
	Dijkstra(s-1);
	for(i=0;i<N;i++){
		if(i!=(s-1)){
			if(AdjacencyList[i].pri != INT_MAX){
				printf("%d ",AdjacencyList[i].pri);
			}
			else{
				printf("%d ",-1);
			}
		}
	}
	printf("\n");
	free(Heap);
	free(AdjacencyList);
	test --;
}
	return 0;
}