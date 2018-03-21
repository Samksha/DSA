#include"qsort.h"

void quickSort(int* arr, int l, int h)
{
	if(l<h)
	{
		int pi = partition(arr, l, h);
//		int pi = medPartition(arr, l, h, h/2);
		quickSort(arr, l, pi-1);
		quickSort(arr, pi, h);
//		l=pi+1;
	}
}
