#include"graph.h"

void seed()
{
	srand(time(NULL));
}

int getRand(int numV)
{
	return rand()%numV;
}

struct graph* createGraph(int numV)
{
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	g->mat = (int**)malloc(sizeof(int*)*numV);
	for(int i = 0; i < numV; i++)
	{
		g->mat[i] = (int*)malloc(sizeof(int*)*numV);
		for(int j = 0; j < numV; j++)
			g->mat[i][j] = 0;
	}

	g->v = (struct vert*)malloc(sizeof(struct vert)*numV);
	for(int i = 0; i < numV; i++)
		g->v[i].val = i;

	g->numV = numV;
	g->numE = 0;
	return g;
}

void addEdge(struct graph* g, struct vert* v, struct vert* vAdj)
{
	g->mat[v->val][vAdj->val] = 1;
//	g->mat[vAdj->val][v->val] = 1;
	g->numE++;
}

void printMat(int** m, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%d ", m[i][j]);
		printf("\n");
	}
}

struct vert* getAdjacent(struct graph* g, struct vert* v)
{
	int deg = degree(g, v);
	struct vert* vtemp = (struct vert*)malloc(sizeof(struct vert)*deg);
	int j = 0;
	for(int i = 0; i < g->numV; i++)
		if(g->mat[v->val][i] == 1)
			vtemp[j++] = g->v[i];
	return vtemp;
}

int degree(struct graph* g, struct vert* v)
{
	int count = 0;
	for(int i = 0; i < g->numV; i++)
		if(g->mat[v->val][i] == 1)
			count++;
	return count;
}

struct vert* bfs(struct graph* g, struct vert* v)
{
	for(int i = 0; i < g->numV; i++)
		g->v[i].visited=0;
	struct Queue q = newQ();
	g->v[0].visited=1;
	q = addQ(q, &g->v[0]);
	while(!isEmptyQ(q))
	{
		struct vert* fr = front(q);
		q = delQ(q);
		if(fr->val == v->val)
			return fr;
		int deg = degree(g, fr);
		struct vert* adj = getAdjacent(g, fr);
		for(int i = 0; i < deg; i++)
		{
			adj[i].visited = 1;
			q = addQ(q, &adj[i]);
		}
	}
/*
	for(int i = 0; i < g->numV; i++)
		if(g->v[i].val == v->val)
		{
			printf("Found vertex\n");
			return v;
		}
	printf("Not found\n");
	return NULL;
*/
}

struct Queue newQ()
{
	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp->front=NULL;
	temp->rear=NULL; 
	temp->size=0;
	return *temp;
}


int isEmptyQ(struct Queue q)
{
	//printf("%d", q.size);
	return (q.size==0);
}

struct Queue delQ(struct Queue q)
{
	if(isEmptyQ(q))
		return q;
	if(q.front->next==NULL) q.rear=NULL;
	q.front = q.front->next;
	q.size--;
	return q;
}

struct Queue addQ(struct Queue q, struct vert* e)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->ele = e;
	temp->next = NULL;
	if(isEmptyQ(q))
	{
		q.front = temp;
		q.rear = temp;
		q.size++;
		return q;
	}
	q.rear->next = temp;
	q.rear = temp;	
	q.size++;
	return q;
}

struct vert* front(struct Queue q)
{
	return q.front->ele;
}

int lengthQ(struct Queue q)
{
	return q.size;
}

void traverse(struct Queue q)
{
	struct Node* current = q.front;
	while(current!=NULL)
	{
		printf("%d ", current->ele->val);
		current = current->next;
	}
}
