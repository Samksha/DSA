#include"SeqList.h"

SeqList newList()
{
	SeqList *sl = (SeqList*)malloc(sizeof(SeqList));
	sl->head=NULL;
	sl->tail=NULL;
	return *sl;
}

SeqList insertAtFront(SeqList sl, Element e)
{
	struct Node *new = (struct Node*)malloc(sizeof(struct Node));
	new->e = e.e;
	new->next = sl.head->next;
	sl.head->next = new;
	return sl;
}

SeqList insertAtEnd(SeqList sl, Element e)
{
	struct Node *new = (struct Node*)malloc(sizeof(struct Node));
	new->e = e.e;
	new->next = NULL;
	sl.tail->next = new;
	return sl;
}

SeqList insertInOrder(SeqList sl, Element e)
{
	struct Node *new = (struct Node*)malloc(sizeof(struct Node));
	new->e = e.e;
	struct Node *temp = sl.head;
	while(temp->next!=NULL && temp->next->e<e.e)
		temp=temp->next;
	new->next = temp->next;
	temp->next = new; 
	return sl;
}

SeqList delete(SeqList sl, Element e)
{
	struct Node* temp = sl.head;
	if(temp!=NULL && temp->e==e.e)
	{
		sl.head=temp->next;
		free(temp);
		return sl;
	}
	struct Node* prev = temp;	
	while(temp!=NULL && temp->e!=e.e)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL) return sl;
	prev->next=temp->next;
	free(temp);
	return sl;
}

SeqList deleteAtFront(SeqList sl)
{
	sl.head=sl.head->next;
	return sl;		
}
