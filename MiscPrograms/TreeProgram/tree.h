#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

typedef enum {true, false} boolean;
struct Node* createNewNode(int d);
void printInOrder(struct Node* n);
void printPreOrder(struct Node* n);
void printPostOrder(struct Node* n);
void bfsTraversal(struct Node* n);
//bfs, dfs
