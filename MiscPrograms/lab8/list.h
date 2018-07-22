#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "BinTree.h"

typedef struct _element * Element;

struct _element{
	Node node;
	Element next; 
};

typedef struct _list * List;

struct _list{
	Element first;
	Element last;
};

List newList();

List pushBack(List, Node);

List append(List, List);

Node popFromFront(List);

int isEmpty(List);

void printList(List);

#endif
