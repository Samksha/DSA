#include "list.h"
#include <stdlib.h>

List newList(){
	List s = (List)malloc(sizeof(struct _list));
	s->first = NULL;
	s->last = NULL;
	return s;
}

List pushBack(List s, Node node){
	Element n = (Element)malloc(sizeof(struct _element));
	n->node = node;
	n->next = NULL;
	if(s->first == NULL){
		s->first = n;
		s->last = n;
		return s;
	}
	else {
		s->last->next = n;
		s->last = n;
	}
	return s;
}

List append(List a, List b){
	if(a == NULL || a->first == NULL)
		return b;
	if(b == NULL || b->first == NULL)
		return a;
	a->last->next = b->first;
	a->last = b->last;
	return a;
}

Node popFromFront(List s){
	if (s->first == NULL){
		return NULL;
	}
	Element n = s->first;
	Node node = n->node;
	s->first = n->next;
	free(n);
	return node;
}

int isEmpty(List s){
	if(s == NULL || s->first == NULL)
		return 1;
	else
		return 0;
}

void printList(List s){
	if(isEmpty(s)){
		printf("List is empty!\n");
		return;
	}
	Element a = s->first;
	while(a!=NULL){
		printf("%d\t",a->node->key);
		a = a->next;
	}
	printf("\n");
}