#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

int main(void){
	int N,E,i,v1,v2,w,s,d;
	extern struct Vertex *AdjacencyList;
	printf("Enter number of vertices\n");
	scanf("%d",&N);
	printf("Enter number of edges\n");
	scanf("%d",&E);

	createGraph(N);
	printf("Enter edges\n");
	while(E!=0){
		//scanf("%d%d%d",&v1,&v2,&w);
		scanf("%d%d",&v1,&v2);
		//addUEdge(v1,v2,w);
		addUEdge(v1,v2);
		E--;
	}
	DFS();
	// printf("Enter Source vertex \n");
	// scanf("%d",&s);
	//Dijkstra(s);
	//Prims(s);
// 	while(d!=-1){
// 	printf("\nEnter Destination \n");
// 	scanf("%d",&d);
// 	PrintPath(d);
// 	if(d<N)
// 	printf("Total cost :%d",AdjacencyList[d].pri);
// }
// 	while(1){
// 	printf("Enter vertex Adjacent \n");
// 	scanf("%d",&v1);
// 	PrintAdjacent(v1);
// }
	//MinimumSpanning();
	return 0;
}
