#include"dag.h"

int main()
{
//	char* filename = "graph0.txt";
	char* filename = "citation.txt";
	graph g = readFile(filename);
//	printGraph(g);
//	printVertices(g);
	vertex* list = topoSort(g);
	for(int i = 0; i < g->numV; i++)
		printf("%d ", list[i]->n);
	printf("\n");
//	printVertices(g);
	return 0;
}
