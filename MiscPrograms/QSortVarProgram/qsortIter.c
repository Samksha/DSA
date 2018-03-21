#include"qsort.h"

void quickSort(int* arr, int l, int h)
{
	int stack[h-l+1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while(top>=0)
	{
		h = stack[top--];
		l = stack[top--];
		int p = partition(arr, l, h);
		if(p-1>l)
		{
			stack[++top] = l;
			stack[++top] = p-1;
		}
		if(p+1<h)
		{
			stack[++top] = p+1;
			stack[++top] = h;
		}
	}
}
