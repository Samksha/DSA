#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include"dfs.h"

typedef struct _element* Element;

struct _element{
	tree node;
	Element next;
};

typedef struct _list* List;

struct _list{
	Element first;
	Element last;
};

typedef tree Node;
List newList();
List add(List, Node);
List append(List, List);
Node getFront(List);
boolean isEmptyL(List);
void printList(List);

#endif
