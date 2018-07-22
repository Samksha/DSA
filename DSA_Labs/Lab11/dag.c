#include"dag.h"

vertex createVertex(int num)
{
	vertex v = (vertex)malloc(sizeof(struct _vertex));
	v->n = num;
	v->indegree = 0;
	v->visited = 0;
	return v;
}

graph createGraph(int numV, int numE)
{
	graph g = (graph)malloc(sizeof(struct _graph));
	g->vlist = (vertex*)malloc(numV*sizeof(vertex));
	g->elist = (edge*)malloc(sizeof(edge));
//	g->elist = (edge*)malloc(sizeof(edge)*numE);
	for(int i = 0; i < numV; i++)
		g->vlist[i] = createVertex(i+1);
	g->numE = 0;
	g->numV = numV;
	return g;
}

void addEdge(graph g, int a, int b)
{
	edge e = (edge)malloc(sizeof(struct _edge));
	e->v1 = g->vlist[a];
	e->v2 = g->vlist[b];
	g->vlist[b]->indegree++;
//	printf("Edge: %d %d\n", e->v1->n, e->v2->n);
	g->elist = (edge*)realloc(g->elist, sizeof(edge)*(g->numE+1));
//	memcpy( (edge*)g->elist + sizeof(edge)*(g->numE-1), e, sizeof(edge) );
	g->elist[g->numE] = e;
	g->numE++;
}

graph readFile(char* filename)
{
	FILE* fp = fopen(filename, "r");

	int numV = 11;
	int numE = 9;

/*
	char* temp = (char*)malloc(sizeof(char)*200);
	int numV, numE;

	fgets(temp, 200, fp);
	printf("%s", temp);
	fgets(temp, 200, fp);
	printf("%s", temp);
	fscanf(fp, "%*s %*s %d %*s %d\n", &numV, &numE);
	fgets(temp, 200, fp);
*/

	printf("# Nodes: %d Edges: %d\n", numV, numE);

	graph g = createGraph(numV, numE);

	int a, b;
	while(!feof(fp))
	{
		fscanf(fp, "%d %d\n", &a, &b);
		printf("%d %d\n", a, b);
		addEdge(g, (a-1)%numV, (b-1)%numV);
//		addEdge(g, a-1, b-1);
	}

	return g;
}

vertex findVertex(graph g)
{
	for(int i = 0; i < g->numV; i++)
		if(g->vlist[i]->indegree == 0 && g->vlist[i]->visited == 0)
			return g->vlist[i];
}

void deleteEdges(graph g, vertex v)
{
	for(int i = 0; i < g->numE; i++)
	{
		if(g->elist[i]->v1 == v)
		{
			g->elist[i]->v2->indegree--;
			g->elist[i]->visited = 1;
//			g->visNumE--;
		}
	}
	v->visited = 1;
	g->visNumV++;
}

vertex* topoSort(graph g)
{
	vertex* sorted = (vertex*)malloc(sizeof(vertex)*g->numV);
	int i = 0;
	g->visNumV = 0;
	while(g->visNumV < g->numV)
	{
		vertex v = findVertex(g);
//		printf("%d ", v->n);
		sorted[i++] = v;
		deleteEdges(g, v);
	}
	return sorted;
}

void printGraph(graph g)
{
	printf("Edges: \n");
	int i = 0;
	for(int i = 0; i < g->numE; i++)
	{
		printf("%d %d\n", g->elist[i]->v1->n, g->elist[i]->v2->n);
	}
}

void printVertices(graph g)
{
	printf("\nVertices:\n");
	for(int i = 0; i < g->numV; i++)
	if(g->vlist[i]->visited == 0)
			printf("%d (%d), ", g->vlist[i]->n, g->vlist[i]->indegree);
	printf("\n");
}
