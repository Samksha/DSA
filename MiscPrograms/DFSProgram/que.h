#include <stdio.h>
#include <stdlib.h>

typedef struct _tnode* Element;
struct Node
{
	Element ele;
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
void addQ(struct Queue* q, Element e);
void delQ(struct Queue* q);
Element getFront(struct Queue* q);
int lengthQ(struct Queue* q);
