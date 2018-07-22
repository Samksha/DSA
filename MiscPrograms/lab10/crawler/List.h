#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct _element * Element;

struct _element{
	int v1;
	int v2;
	Element next; 
};

typedef struct _list * List;

struct _list{
	Element first;
	Element last;
};

List newList();

List pushBack(List, int, int);

List append(List, List);

int isEmptyList(List);

void printList(List);

#endif
