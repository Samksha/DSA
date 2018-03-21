#include"gtp.h"

boolean isEmptyQ(struct Queue* q)
{
	return (q->size==0);
}

struct Queue createNewQ()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front=NULL;
	q->rear=NULL;
	q->size=0;
	return *q;
}

void addQ(struct Queue* q, struct TNode* d)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->n=d;
	//temp->data=d;
	temp->next=NULL;
	if(isEmptyQ(q))
	{
		q->front=temp;
		q->rear=temp;
		q->size++;
		return;
	}
	q->rear->next=temp;
	q->rear=temp;
	q->size++;
	return;
}

void delQ(struct Queue* q)
{
	if(isEmptyQ(q)) return;
	if(q->front->next==NULL)
	{
		q->front=NULL;
		q->rear=NULL;
		q->size--;
		return;
	}
	q->front = q->front->next;
	q->size--;
	return;
}

int getFront(struct Queue* q)
{
	return (q->front->n->data);
}

int lengthQ(struct Queue* q)
{
	return (q->size);
}

void traverse(struct Queue* q)
{
	struct Node* current = q->front;
	while(current!=NULL)
	{
		printf("%d ", current->n->data);
		current = current->next;
	}
}

