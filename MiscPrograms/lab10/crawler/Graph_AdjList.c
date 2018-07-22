#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Graph_AdjList.h"
#include "Queue.h"

Graph newGraph(){
	Graph g = (Graph)malloc(sizeof(struct _graph));
	g->numV = 0;
	g->adjList = newList();
	g->vertices = (Vertex*)malloc(sizeof(Vertex)*100);
	return g;
}

Graph addNode(Graph g, Vertex v){
	if(getIndex(g,v) != -1)
		return g;
	if(g->numV != 0 && g->numV%100 == 0)
		g->vertices = (Vertex*)realloc(g->vertices,sizeof(Vertex)*(g->numV+100));
	g->vertices[g->numV] = v;
	++(g->numV);
	printf("Node added: %s !\n",v->name);
	return g;
}

int getIndex(Graph g, Vertex v){
	int i = 0;
	if(g == NULL || g->numV ==0 || g->vertices == NULL)
		return -1;
	while(i<g->numV){
		if(!strcmp(g->vertices[i]->name,v->name))
			return i;
		++i;
	}
	return -1;
}

int* getAdjacent(Graph g, Vertex v){
	int *arr = (int*)malloc(sizeof(int)*g->numV);
	int i,j,count = 0;
	j = getIndex(g,v);
	Element ls = g->adjList->first;
	while(ls!=NULL){
		if(ls->v1 == j){
			arr[count++] = ls->v2;
		}
		ls = ls->next;
	}
	arr[count] = -1;
	return arr;
}

Graph addEdge(Graph g, Vertex v, Vertex vAdj){
	if(g == NULL)	return g;
	int i = getIndex(g,v);
	int j = getIndex(g,vAdj);
	if(i == -1 || j == -1){
		if(i == -1){
			g = addNode(g,v);
			i = g->numV-1;
		}
		if(j == -1){
			g = addNode(g,vAdj);
			j = g->numV-1;
		}
	}
	else{
		Element ls = g->adjList->first;
		while(ls!=NULL){
			if(ls->v1 == i && ls->v2 == j){
				printf("Edge %s -> %s already exists!\n",g->vertices[ls->v1]->name,g->vertices[ls->v2]->name);
				return g;
			}
			ls = ls->next;
		}
	}	
	g->adjList = pushBack(g->adjList,i,j);
	printf("Added edge %s -> %s !\n",g->vertices[i]->name,g->vertices[j]->name);
	return g;
}

int degree(Graph g, Vertex v){
	int i,j = getIndex(g,v),count = 0;
	if(j == -1)
		return -1;
	Element ls = g->adjList->first;
	while(ls!=NULL){
		if(ls->v1 == j || ls->v2 == j && ls->v1!=ls->v2)
			++count;
		ls = ls->next;
	}
	return count;
}

/*
void BFT(Graph g, Vertex v){
	if(g==NULL || g->numV <= 0)
		return;
	int index = getIndex(g,v);
	if(index == -1){
		printf("No such element!\n");
		return;
	}
	printf("The breadth-first traversal starting from %s is:\n\t",v->name);
	int *visited = (int*)malloc(sizeof(int)*g->numV);
	Queue q = newQueue();
	q = push(q,index);
	int i=0;
	int *arr;
	for(i=0; i<g->numV; ++i)
		visited[i] = 0;
	visited[index]=1;
	while(!isEmptyQ(q)){
		index = pop(q);
		printf("%s\t",g->vertices[index]->name);
		arr = getAdjacent(g,g->vertices[index]);
		for(i=0; arr[i]!=0; ++i){
			if(visited[arr[i]] == 0){
				q = push(q,arr[i]);
				visited[arr[i]] = 1;
			}
		}
		free(arr);
	}
	printf("\n");
}
*/