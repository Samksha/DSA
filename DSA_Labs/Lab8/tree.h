#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
	int bal;
};

struct BinTree
{
	struct Node* root;
	int size;
};

int getRand();
void seed();
struct BinTree* createTree();
struct Node* createNode(int v);
void addNode(struct BinTree* bt, int v);
void setNodeVals(struct BinTree* bt);
struct Node* findNode(struct BinTree* bt, int key);
struct Node* findNode_(struct Node* n, int key);
void deleteNode(struct BinTree* bt, int key);
void inOrderPrint(struct Node* root);
struct Node* inOrderSucc(struct BinTree* bt, struct Node* node);
