#include"list.h"
#include <stdlib.h>

List newList()
{
	List temp = (List)malloc(sizeof(struct _list));
	temp->first = NULL;
	temp->last = NULL;
	return temp;
}

List add(List l, tree node)
{
	Element temp = (Element)malloc(sizeof(struct _element));
	temp->node = node;
	temp->next = NULL;
	if(l->first == NULL)
	{
		l->first = temp;
		l->last = temp;
		return l;
	}
	l->last->next = temp;
	l->last = temp;
	return l;
}

List append(List a, List b)
{
	if(a==NULL || a->first == NULL) return b;
	if(b==NULL || b->first == NULL) return a;
	a->last->next = b->first;
	a->last = b->last;
	return a;
}

tree getFront(List l)
{
	if(l->first == NULL) return NULL;
	Element temp = l->first;
	tree node = temp->node;
	l->first = temp->next;
	free(temp);
	return node;
}

boolean isEmptyL(List l)
{
	if(l == NULL || l->first == NULL) return true;
	else return false; 
}

void printList(List l)
{
	if(isEmptyL(l))
		return;
	Element temp = l->first;
	while(temp!=NULL)
	{
		printf("%d ", temp->node->val);
		temp = temp->next;
	}
	printf("\n");
}
