#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct _tree
{
	int key;
	struct _tree* left;
	struct _tree* right;
	int balance;
};

typedef struct _tree* Tree;
typedef Tree Node;

Tree createTree(int);
void seed();
int getRand();
Tree add(Tree t, int val);
Tree addNode(Tree, Node);
Tree avlAddNode(Tree, Node);
Node find(Tree, int);
Tree inOrderSuccessor(Tree, Node);
Tree delete(Tree, int);
Tree avlDelete(Tree, int);
void clearTree(Tree);
Tree rotate(Tree, Node, Node, Node);
Node inOrder(Tree, int);
void inOrderPrint(Tree);
int recursiveHeight(Tree t);

/*
void setVals(struct Tree* t);
void inOrderPrint(struct Tree* t);
void inOrderPrint_(struct Node* n);
struct Node* findNode(struct Tree* t, int key);
struct Node* findNode_(struct Node* t, int key);
int getBalance(struct Node* n);
struct Node* leftRotate(struct Node* x);
struct Node* rightRotate(struct Node* y);
int max(int a, int b);
*/
