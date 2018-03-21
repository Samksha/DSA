#include"llp.h"

double heap_mem = 0;

void* myalloc(long size)
{
	char* buffer = (char*)malloc(sizeof(int)+size);
	if(buffer == NULL) return NULL;

	int* sizeBox = (int*)buffer;
	*sizeBox = size;
	heap_mem += size;
	return buffer + sizeof(int);
}

void myfree(void* temp)
{
	if(temp == NULL) return;

	char* buffer = (char*)temp + sizeof(int);
	int* sizeBox = (int*)buffer;
	heap_mem-=*sizeBox;
	free(buffer);
}

int getRand()
{
	srand(time(NULL));
	return ((rand()%15000)+10000);
}

boolean isEmpty(struct LList* list)
{
	return (list->size==0);
}

void addNode(struct LList* list, long d)
{
	struct Node* temp = (struct Node*)myalloc(sizeof(struct Node));
	temp->data = d;
	temp->next = NULL;
	if(list->size==0)
	{
		list->head=temp;
		list->tail=temp;
		list->size++;
		return;
	}
	list->tail->next = temp;
	list->tail = list->tail->next;
	list->size++;
}

struct LList createList(long n)
{
	long i;
	struct Node* temp = (struct Node*)myalloc(sizeof(struct Node));
	struct LList* list = (struct LList*)myalloc(sizeof(struct LList));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	srand(time(NULL));
	for(i=0; i<n; i++)
		addNode(list, rand()%15000);
	return *list;
}

void createCycle(struct LList* list, long n)
{
	srand(time(NULL));
	int flip = rand()%2;
//	int flip = 0;
	if(flip==0) return;
	long r = rand()%n;
	long i;
	struct Node* temp = list->head;
	for(i=0; i<r; i++)
		temp=temp->next;
	list->tail->next=temp;
}

/*
boolean testCyclic(struct LList* list)
{
	return false;
}
*/

void makeCircularList(struct LList* list)
{
	int t = testCyclic(list);
	if(t==0)
	{
		list->tail->next = list->head;
		return;
	}
	struct Node* cyc = getCycle(list);
	struct Node* temp = list->head;
	struct Node* temp2 = temp;
	while(temp!=cyc)
	{
		temp2 = temp;
		temp = temp->next;
//		myfree(temp2);	
	}
}

struct Node* getCycle(struct LList* list)
{
	struct Node* hare = list->head;
	struct Node* tort = list->head;
	while(1)
	{
		if(hare == NULL) return NULL;
		hare = hare->next;
	
		if(hare == NULL) return NULL;
		hare = hare->next;
		
		tort = tort->next;
		if(hare == tort) return tort;
	}
}

void printList(struct LList* list)
{
	struct Node* temp = list->head;
	while(temp!=NULL)
	{	
		printf("%ld ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
