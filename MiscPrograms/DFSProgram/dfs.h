#ifndef TREE_H
#define TREE_H

#include <time.h>
typedef enum boolean {false, true} boolean;

typedef struct _iterator* iter;
typedef iter* Iterator;

struct _tree
{
	int val;
	iter children;
};
typedef struct _tree* tree;

void seed();
int getRand();
void visit(tree a);
tree createNode(int v, int n);
tree createTree(int);
void bft(tree a);
void dft(tree a);

#endif
