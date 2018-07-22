#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _vertex
{
	int n;
	int indegree;
	int visited;
};
typedef struct _vertex* vertex;

struct _edge
{
	vertex v1;
	vertex v2;
	int visited;
};
typedef struct _edge* edge;

struct _graph
{
	vertex* vlist;
	edge* elist;
	int numV;
	int numE;
//	int visNumE;
	int visNumV;
};
typedef struct _graph* graph;

graph readFile(char* filename);
graph createGraph(int numV, int numE);
void addEdge(graph g, int a, int b);
void printGraph(graph g);
void printVertices(graph g);
vertex* topoSort(graph g);

