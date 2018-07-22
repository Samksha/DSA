#include"iter.h"

int main()
{
	int n = 5;
	int* arr = createArr(n);

	iterator* it = createIterator(arr);	
	
	while(!hasMoreElements(it))
	{
		printf("%d ", getNextElement(it));	
	}
/*
	int a = getNextElement(it);
	printf("%d\n", a);

	int b = getNextElement(it);
	printf("%d\n", b);
*/
	return 0;
}
