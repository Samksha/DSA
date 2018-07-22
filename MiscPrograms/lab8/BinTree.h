#ifndef BINTREE_H
#define BINTREE_H

#include <stdlib.h>

typedef struct _tree * Tree;

typedef Tree Node;

struct _tree{
	int key;
	Tree left;
	Tree right;
	int balance;
};

#include "list.h"

extern struct _list;
typedef struct _list * List;

Tree newTree(int);

Tree add(Tree, int);

Tree add_node(Tree, Node);

Tree AVL_add_node(Tree, Node);

Node find(Tree, int);

Tree inOrderSuccessor(Tree, Node);

Tree delete(Tree, int);

Tree AVL_delete(Tree, int);

void clearTree(Tree);

Tree rotate(Tree, Node, Node, Node);

Node inOrder(Tree, int);

List inRange(Tree, int, int);

#endif