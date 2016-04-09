#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

int main(void){
	int N,E,i,v1,v2,w,s,d,Test;
	extern struct Vertex *AdjacencyList;
	extern struct Vertex *AdjacencyList2;
	scanf("%d",&Test);
	while(Test>0){
	scanf("%d",&N);
	E = N-1;
	createGraph(N);
	while(E!=0){
		//scanf("%d%d%d",&v1,&v2,&w);
		scanf("%d%d",&v1,&v2);
		//addUEdge(v1,v2,w);
		//addUEdge(v1,v2);
		addUEdge(v1-1,v2-1);
		E--;
	}
	childCount();
	Answer();
	Test--;
}
	
	return 0;
}
