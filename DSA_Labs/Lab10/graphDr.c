#include"graph.h"

int main()
{
	int numV = 4;
	struct graph* g = createGraph(numV);
	printf("Created Graph:\n");
	printMat(g->mat, numV);
	for(int i = 0; i < 5; i ++)
		addEdge(g, &g->v[getRand(numV)], &g->v[getRand(numV)]);
	printf("Updated Graph:\n");
	printMat(g->mat, numV);
	for(int i = 0; i < numV; i++)
	{
		int deg = degree(g, &g->v[i]);
		printf("Degree of vertex %d = %d\n", i, deg);
		struct vert* v = getAdjacent(g, &g->v[i]);
		printf("Adjacencies of vertex %d = ", i);
		for(int j = 0; j < deg; j++)
			printf("%d ", v[j].val);
		printf("\n");
	}
	struct vert* v = bfs(g, &g->v[3]);
	printf("Found vertex = %d\n", v->val);

//	struct graph* crawler = createGraph(200);
	
//	for(int i = 0; i < numV; i++)
//		printf("%d ", g->v[i].val);
	return 0;
}
