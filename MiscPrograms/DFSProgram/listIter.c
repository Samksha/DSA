#include <stdlib.h>
#include"listIter.h"

boolean hasMoreElements(Iterator it)
{
	if(it!=NULL && *it!=NULL && (*it)->t!=NULL) return true;
	else return false;
}

tree getNextElement(Iterator it)
{
	if(!hasMoreElements(it)) return NULL;
	tree t = (*it)->t;
	*it = (*it)->next;
	return t;
}

List makeList(Iterator it)
{
	List s = newList();
	while(hasMoreElements(it))
		s = add(s, getNextElement(it));
	return s;
}
