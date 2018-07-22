#include <stdio.h>
#include <stdlib.h>

typedef long element;

struct SNode
{
	element data;
	struct SNode* next;
	struct SNode* prev;
};

struct Stack
{
	struct Node* top;
	unsigned size;
};

typedef enum {true, false} boolean;
boolean isEmpty(struct Stack* s);
struct Stack* createNewS();
void push(struct Stack* s, long d);
void pop(struct Stack* s);
struct SNode* peek(struct Stack* s);
int getLength(struct Stack* s);
