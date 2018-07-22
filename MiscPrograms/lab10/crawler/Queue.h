#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

typedef struct _node * Node;

struct _node{
	int v;
	Node next; 
};

typedef struct _queue * Queue;

struct _queue{
	Node first;
	Node last;
};

Queue newQueue();

Queue push(Queue, int);

int pop(Queue);

int isEmptyQ(Queue);

void printQ(Queue);

#endif
