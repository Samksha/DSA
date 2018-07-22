#include <stdio.h>
#include <stdlib.h>

struct _tree
{
	struct _tree* left;
	struct _tree* right;
	int key;
};

typedef struct _tree* tree;

tree createNode(int);
tree add(tree, int);
tree addNode(tree, tree);
tree insert(tree, int);
tree delete(tree, int);
void inOrder(tree);
