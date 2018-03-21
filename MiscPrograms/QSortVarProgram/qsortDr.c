#include"qsort.h"

int main()
{
	seed();
	int n = 20;
	int * arr = createArr(n);
	printArr(arr, n);
	quickSort(arr, 0, n-1);
	printArr(arr, n);
	return 0;
}
