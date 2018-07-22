#include "List.h"
#include <stdlib.h>
#include "Graph_AdjList.h"

List newList(){
	List s = (List)malloc(sizeof(struct _list));
	s->first = NULL;
	s->last = NULL;
	return s;
}

List pushBack(List s, int v1, int v2){
	Element n = (Element)malloc(sizeof(struct _element));
	n->v1 = v1;
	n->v2 = v2;
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

int isEmptyList(List s){
	if(s == NULL || s->first == NULL)
		return 1;
	else
		return 0;
}

void printList(List s){
	if(isEmptyList(s)){
		printf("List is empty!\n");
		return;
	}
	Element a = s->first;
	while(a!=NULL){
		printf("%d -> %d\t",a->v1,a->v2);
		a = a->next;
	}
	printf("\n");
}
