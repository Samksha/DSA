#include <stdio.h>
#include <stdlib.h>

struct Node
{
	long data;
	struct Node* next;
	struct Node* prev;
};

struct Stack
{
	struct Node* top;
	unsigned size;
};

typedef enum {true, false} boolean;
boolean isEmpty(struct Stack* s);
struct Stack createNewS();
void push(struct Stack* s, long d);
void pop(struct Stack* s);
struct Node* peek(struct Stack* s);
int getLength(struct Stack* s);
