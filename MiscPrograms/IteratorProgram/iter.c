#include"iter.h"

iterator* createIterator(element* arr)
{
	iterator* it = (iterator*)malloc(sizeof(iterator));
	it->itr = arr;
	it->index = 0;
	return it;
}

element* createArr(int n)
{
	element* arr = (element*)malloc(sizeof(element)*n);
	for(int i = 0; i < n; i++)
		arr[i] = i+1;
	return arr;
}

boolean hasMoreElements(iterator* it)
{
	return it->itr[it->index]==32767;
}

element getNextElement(iterator* it)
{
	return it->itr[it->index++];
/*
	element temp = it[0][0];
	it++;
//	it += sizeof(*it);
	return temp;
*/
}
