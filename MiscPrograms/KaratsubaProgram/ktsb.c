#include"ktsb.h"

boolean isEmptyQ(struct Queue* q)
{
	return (q->size==0);
}

struct TNode* createNewT(long d)
{
	struct TNode* temp = (struct TNode*)malloc(sizeof(struct TNode));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=d;
	return temp;
}

struct Queue createNewQ()
{
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front=NULL;
	q->rear=NULL;
	q->size=0;
	return *q;
}

void addQ(struct Queue* q, struct TNode* t)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->n = t;
	temp->next = NULL;
	if(isEmptyQ(q))
	{
		q->front=temp;
		q->rear=temp;
		q->size++;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
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
	q->front=q->front->next;
	q->size--;
}

int lengthQ(struct Queue* q)
{
	return (q->size);
}

struct TNode* getFront(struct Queue* q)
{
	//printf("%ld\n", q->front->n->data);
	if(q->size==0) return NULL;
	return q->front->n;
}

void traverseQ(struct Queue* q)
{
	struct Node* curr = q->front;
	while(curr!=NULL)
	{
		printf("%ld ", curr->n->data);
		curr=curr->next;
	}
	printf("\n");
}

void printLevelOrder(struct TNode* root)
{
	struct Queue q = createNewQ();
	struct TNode* temp = root;
	addQ(&q, root);
	while(temp!=NULL)
	{
		printf("%ld ", temp->data);
		if(temp->left!=NULL)
			addQ(&q, temp->left);
		if(temp->right!=NULL)
			addQ(&q, temp->right);
//		traverseQ(&q);
		delQ(&q);
		temp = getFront(&q);
//		traverseQ(&q);
	}
}

void addRightNode(struct TNode* t, long d)
{
	t->right = createNewT(d);
}

void addLeftNode(struct TNode* t, long d)
{
	t->left = createNewT(d);
}

struct Stack createNewS()
{
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = NULL;
	s->size=0;
	return *s;
}

boolean isEmptyS(struct Stack* s)
{
	return (s->size==0);
}

void push(struct Stack* s, struct TNode* t)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->n = t;
	temp->next = NULL;
	if(isEmptyS(s))
	{
		s->top=temp;
		s->size++;
		return;
	}
	s->top->next = temp;
	s->top = temp;
	s->size++;
}

/*
struct TNode* pop(struct Stack* s)
{
	if(isEmptyS(s)) return;
	struct TNode* t = s->top;
	if(s->top->next==NULL)
	{	
		s->top=NULL;
		s->size--;
		return t;
	}
	s->top = s
}
*/
