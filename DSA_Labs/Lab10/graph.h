#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
	struct vert* ele;
 	struct Node* next;
};

struct Queue
{
	struct Node* front;
	struct Node* rear;
	int size;
};

struct vert
{
	int val;
	int visited;
};

struct edge
{
	struct vert* v1;
	struct vert* v2;
};

struct graph
{
	int** mat;
	struct vert* v;
//	struct edge* e;
	int numE;
	int numV;
};

void seed();
int getRand(int numV);
struct graph* createGraph(int numV);
struct vert* getAdjacent(struct graph* g, struct vert* v);
void addEdge(struct graph* g, struct vert* v, struct vert* vAdj);
int degree(struct graph* g, struct vert* v);
void printMat(int** m, int n);
struct vert* bfs(struct graph* g, struct vert* v);
struct Queue newQ();
int isEmptyQ(struct Queue q);
struct vert* front(struct Queue q);
struct Queue addQ(struct Queue q, struct vert* e);
struct Queue delQ(struct Queue q);
int lengthQ(struct Queue q); 
void traverse(struct Queue q);

