#include"stack.h"

struct Stack createNewS()
{
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top=NULL;
	s->size=0;
	return *s;
}

boolean isEmptyS(struct Stack* s)
{
	return (s->size==0);
}

int getSize(struct Stack* s)
{
	return s->size;
}

void push(struct Stack* s, long d)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = d;
	temp->next = NULL;	
	if(isEmptyS(s))
	{
		temp->prev = NULL;
		s->top = temp;
		s->size++;
		return;
	}
	temp->prev = s->top;
	s->top->next = temp;
	s->top = temp;
	s->size++;
	return;
}

void pop(struct Stack* s)
{
	if(isEmptyS(s)) return;
	s->size--;
	struct Node* temp = s->top;
	s->top = s->top->prev;
	s->top->next = NULL;
}
