#include <stdio.h>
#include <stdlib.h>

struct TNode
{
	int data;
	struct TNode* left;
	struct TNode* right;
};

struct Node
{
	struct TNode* n;
	struct Node* next;
};

struct Queue
{
	struct Node* front;
	struct Node* rear;
	unsigned size;
};

typedef enum { true, false } boolean;
boolean isEmptyQ(struct Queue* q);
struct Queue createNewQ();
void addQ(struct Queue* q, struct TNode* d);
void delQ(struct Queue* q);
int lengthQ(struct Queue* q);
int getFront(struct Queue* q);
void traverse(struct Queue* q);
