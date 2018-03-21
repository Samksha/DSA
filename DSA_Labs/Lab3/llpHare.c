#include"llp.h"

boolean testCyclic(struct LList* list)
{
	if(isEmpty(list)) return false;
	struct Node* hare = list->head;
	struct Node* tort = list->head;
	if(hare->next==hare || hare->next->next==hare) return true;
	while(hare->next != tort || hare != tort)
	{
		if(hare->next==NULL || hare == NULL) return false;
		hare = hare->next->next;
		tort = tort->next;
	} 
	return true;
}
