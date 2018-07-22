#include <stdio.h>
#include <stdlib.h>
#include"que.h"

typedef struct node* element;

//typedef element* iterator;

struct _iterator
{
	element* itr;
	int index;
};

typedef struct _iterator iterator;

//typedef enum {true, false} boolean;

iterator* createIterator(element* arr);
element* createArr(int n);
boolean hasMoreElements(iterator* it);
element getNextElement(iterator* it);
