#ifndef GRAPH_H
#define GRAPH_H

typedef struct _vertex * Vertex;

struct _vertex{
	char* name;
	char* url;
};

#include <string.h>

#define BROKEN(s) ((s)->name = "#BROKEN#")
#define INVALID(s) (strcpy((s)->name,"@invalid@"))
#define IS_INVALID(s) (!(strcmp((s)->name,"@invalid@")))

#include "List.h"

struct _graph{
	int numV;
	List adjList;
	Vertex* vertices;
};

typedef struct _graph * Graph;

Graph newGraph();

Graph addNode(Graph, Vertex);

int getIndex(Graph, Vertex);

int* getAdjacent(Graph, Vertex);

Graph addEdge(Graph, Vertex, Vertex);

int degree(Graph, Vertex);

// void BFT(Graph, Vertex);

#endif
