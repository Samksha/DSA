#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include"dfs.h"
#include"list.h"

typedef struct _iterator* iter; 

struct _iterator
{
	tree t;
	iter next;
};

typedef iter* Iterator;

boolean hasMoreElements(Iterator it);

tree getNextElement(Iterator it);

List makeList(Iterator);

#endif
