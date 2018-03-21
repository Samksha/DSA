#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
	long data;
	struct Node* next;
};

struct LList
{
	unsigned size;
	struct Node* head;
	struct Node* tail;
};

typedef enum {false, true} boolean;

void* myalloc(long size);
void myfree(void* temp, long size);

long getRand();

void allocateArr();

boolean isEmpty(struct LList* list);
void addNode(struct LList* list, long d);
struct LList createList(long n);
void createCycle(struct LList* list, long size);
void printList(struct LList* list);
int testCyclic(struct LList* list);
