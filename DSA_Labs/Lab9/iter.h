#include"nary.h"

/*struct iterator
{

};*/

typedef struct lnode* iterator;

int hasMoreElements(iterator it)
{
	if(isEmpty(it))
		return 0;
	else
		return 1;
}

struct tnode* getNextElement(iterator it)
{
	return delNode(it);
}
