#include"que.h"

struct Queue newQ()
{
	struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
	temp->front=NULL;
	temp->rear=NULL; 
	temp->size=0;
	return *temp;
}


int isEmptyQ(struct Queue q)
{
	//printf("%d", q.size);
	return (q.size==0);
}

struct Queue delQ(struct Queue q)
{
	if(isEmptyQ(q))
		return q;
	if(q.front->next==NULL) q.rear=NULL;
	q.front = q.front->next;
	q.size--;
	return q;
}

struct Queue addQ(struct Queue q, Element e)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->ele = e;
	temp->next = NULL;
	if(isEmptyQ(q))
	{
		q.front = temp;
		q.rear = temp;
		q.size++;
		return q;
	}
	q.rear->next = temp;
	q.rear = temp;	
	q.size++;
	return q;
}

Element front(struct Queue q)
{
	return q.front->ele;
}

int lengthQ(struct Queue q)
{
	return q.size;
}

void traverse(struct Queue q)
{
	struct Node* current = q.front;
	while(current!=NULL)
	{
		printf("%d ", current->ele);
		current = current->next;
	}
}
