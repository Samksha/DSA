#include <stdio.h>
#include <stdlib.h>

typedef long Element;
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

typedef enum { true, false } Boolean;

Boolean isEmptyQ(struct Queue* q);
struct Queue createNewQ();
void addQ(struct Queue* q, Element e);
void delQ(struct Queue* q);
Element getFront(struct Queue* q);
int lengthQ(struct Queue* q);
