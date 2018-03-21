#include <stdio.h>
#include <stdlib.h>

//Node for the binary tree - contains data, left child, right child
struct TNode
{
	long data;
	struct TNode* left;
	struct TNode* right;
};

//Node for the queue - connect to next, TNode
struct Node
{
	struct TNode* n;
	struct Node* next;
};

//Queue - front and rear pointers
struct Queue
{
	struct Node* front;
	struct Node* rear;
	unsigned size;
};

//Stack - front and rear pointers
struct Stack
{
	struct Node* top;
	unsigned size;
};

typedef enum { true, false } boolean;

//Queue Utility Functions
boolean isEmptyQ(struct Queue* q);
struct Queue createNewQ();
void addQ(struct Queue* q, struct TNode* t);
void delQ(struct Queue* q);
int lengthQ(struct Queue* q);
struct TNode* getFront(struct Queue* q);
void traverseQ(struct Queue* q);

//Tree Utility Functions
void printLevelOrder(struct TNode* t);
void addLeftNode(struct TNode* t, long d);
void addRightNode(struct TNode* t, long d);
struct TNode* createNewT();
void printLevelOrder(struct TNode* root);

//Stack Utility Functions
struct Stack createNewS();
void push(struct Stack* s, struct TNode* t);
struct TNode* pop(struct Stack* s);
boolean isEmptyS(struct Stack* s);
struct TNode* peek(struct Stack* s);
