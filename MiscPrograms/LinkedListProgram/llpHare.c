#include"llp.h"

int testCyclic(struct LList* list)
{
	struct Node* hare = list->head;
	struct Node* tort = list->head;
	while(1)
	{
		if(hare == NULL) return 0;
		hare = hare->next;
		
		if(hare == NULL) return 0;
		hare = hare->next;
				
		tort = tort->next;
		if(hare == tort) return 1;
	}
	/*
	
	if(isEmpty(list)) return false;
	if(hare->next == hare || hare->next->next == hare)
		return true;
	
	while(hare!=tort||hare->next!=tort)
	{
		hare=hare->next->next;
		tort=tort->next;
		if(hare==NULL || hare->next->next==NULL)
			return false;
	}
	return true;
	*/
}
