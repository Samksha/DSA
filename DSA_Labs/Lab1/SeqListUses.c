#include"SeqList.h"

SeqList merge(SeqList sl1, SeqList sl2)
{
	struct Node* head = NULL;
	if(sl1.head==NULL)
		return sl2;
	else if(sl2.head==NULL)
		return sl1;

	if(sl1.head->e < sl2.head->e)
	{
		head=sl1.head;
		head->next=merge(sl1.head->next, sl2);
	}
	else
	{
		head=sl2.head;
		head->next=merge(sl1, sl2.head->next);
	}
	SeqList sl;
	sl.head=head;
	sl.tail=NULL; 
	return sl;
}
