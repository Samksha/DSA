#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double heap_mem = 0;
struct Node
{
	int data;
	struct Node* next;
};

struct Queue
{
	int size;
	struct Node* front;
};

void* myalloc(long size);
void myfree(void* temp);
int getRand();
