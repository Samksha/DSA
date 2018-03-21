#include"llp.h"

void reverse(struct LList* list)
{
	struct Node* prev = NULL;
	struct Node* curr = list->head;
	struct Node* next = NULL;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	}
	list->head = prev;
}

//if(curr==list->head && curr == NULL) cyclic else linear
