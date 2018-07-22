#include"que.h"

struct Queue createNewQ()
{
	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp->rear=NULL;
	temp->front=NULL;
	temp->size=0;
	return *temp;
}

boolean isEmptyQ(struct Queue* q)
{
	return (q->size==0);
}

void addQ(struct Queue* q, Element e)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->next=NULL;
	temp->ele=e;
	if(isEmptyQ(q))
//	if(q->size==0) 
	{
		q->front = temp;
		q->rear = temp;
		q->size++;
		return;
	}
	else
	{
		q->rear->next = temp;
		q->rear = temp;
		q->size++;
		return;
	}
}

void delQ(struct Queue* q)
{
	if(isEmptyQ(q)) return;
//	if(q->size==0) return;
	if(q->front->next==NULL)
	{
		q->front=NULL;
		q->rear=NULL;
		q->size--;
		return;
	}
	q->front = q->front->next;
	q->size--;
//	if(q->front->next == NULL) q->rear=q->front;
}

Element getFront(struct Queue* q)
{
	if(isEmptyQ(q)) return NULL;
//	if(q->size==0) return -1;
	return q->front->ele;
}

int lengthQ(struct Queue* q)
{
	return q->size;
}
