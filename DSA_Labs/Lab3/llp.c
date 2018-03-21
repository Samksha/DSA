#include"llp.h"

double heap_mem=0;

void* myalloc(long size)
{
	if(malloc(size)==NULL)
	{
		printf("%f ", heap_mem);
		 return NULL;
	}
	heap_mem=heap_mem+size;
	return malloc(size);
}

void myfree(void* temp, long size)
{
//	printf("%ld \n", sizeof(temp));
	heap_mem=heap_mem-(size);
	free(temp);
}

long getRand()
{
	srand(time(NULL));
	return ((rand()%15000) + 10000);
}

void allocateArr()
{
	long size = getRand();
	int* arr = (int*)myalloc(size*sizeof(int));
	printf("%p %p %p\n", &arr[0], &arr[1], &arr[size-1]);
	printf("%f \n", heap_mem);
	myfree(arr, size*sizeof(*arr));
	printf("%f \n", heap_mem);
}

boolean isEmpty(struct LList* list)
{
	return (list->size==0);
}

void addNode(struct LList* list, long d)
{
	struct Node* temp = (struct Node*)myalloc(sizeof(struct Node));
	temp->next = NULL;
	temp->data = d;
	if(isEmpty(list))
	{
		list->head = temp;
		list->tail = temp;
		list->size++;
		return;
	}
	list->tail->next = temp;
	list->tail = temp;
	list->size++;
}

struct LList createList(long n)
{
	int i;
	long d;
	struct LList* list = (struct LList*)myalloc(sizeof(struct LList));
	list->size=0;
	list->head=NULL;
	list->tail=NULL;
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		d = rand()%30000;
//		printf("%ld ", d);
		addNode(list, d);
	}
	return *list;
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

void createCycle(struct LList* list, long size)
{
//	int flip = rand()%2;
	int flip=1;
	if(flip==0) return;
	long r = rand()%size;
	long i;
	struct Node* temp = list->head;
	for(i=0; i<r; i++)
	{
		temp = temp->next;
	}
	list->tail->next = temp;
	printf("Cycle created \n");
	return;
}

int testCyclic(struct LList* list)
{
	struct Node* hare = list->head;
	struct Node* tort = list->head;
	while(1)
	{
		if(hare==NULL) return 0;
		hare = hare->next;

		if(hare==NULL) return 0;
		hare = hare->next;

		tort = tort->next;

		if(hare==tort) return 1;
	}
}

int testCyclic2(struct LList* list)
{
	struct Node* prev = NULL;
	struct Node* curr = list->head;
	struct Node* nxt = list->head->next;
	while(1)
	{
		curr->next=prev;
		
		temp->next = temp;
		temp = temp->next;
	}
}
