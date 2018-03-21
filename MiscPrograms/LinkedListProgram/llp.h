#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//double heap_mem=0;

struct Node
{
	long data;
	struct Node* next;
};

struct LList
{
	struct Node* head;
	struct Node* tail;
	unsigned size;
};

typedef enum {false, true} boolean;

void* myalloc(long size);
void myfree(void* temp);
int getRand();

boolean isEmpty(struct LList* list);
void addNode(struct LList* list, long d);
struct LList createList(long n);

void createCycle(struct LList* l, long n);
int testCyclic(struct LList* l);
void printList(struct LList* list);
void makeCircularList(struct LList* list);
struct Node* getCycle(struct LList* list);
