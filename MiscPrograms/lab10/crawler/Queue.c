#include "Queue.h"
#include <stdlib.h>

#define INVALID -32000

Queue newQueue(){
	Queue s = (Queue)malloc(sizeof(struct _queue));
	s->first = NULL;
	s->last = NULL;
	return s;
}

Queue push(Queue s, int v){
	Node n = (Node)malloc(sizeof(struct _node));
	n->v = v;
	n->next = NULL;
	if(s->first == NULL){
		s->first = n;
		s->last = n;
		return s;
	}
	else {
		s->last->next = n;
		s->last = n;
	}
	return s;
}

int pop(Queue s){
	if(isEmptyQ(s))
		return INVALID;
	int v = s->first->v;
	s->first = s->first->next;
	return v;
}

int isEmptyQ(Queue s){
	if(s == NULL || s->first == NULL)
		return 1;
	else
		return 0;
}

void printQ(Queue s){
	if(isEmptyQ(s)){
		printf("Queue is empty!\n");
		return;
	}
	Node a = s->first;
	while(a!=NULL){
		printf("%d\t",a->v);
		a = a->next;
	}
	printf("\n");
}
