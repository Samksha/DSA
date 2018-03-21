#include"sort.h"

int main()
{
	seed();
	int n = 10;
	struct Empl** arr = createArr(n);
	FILE* fp;
	fp = fopen("data.txt", "r");
	read(fp, arr);
	printArr(arr, n);
//	quickSortRec(arr, 0, 9);
	quickSort(arr, 0, n-1, 10);
//	insertionSort(arr, n);
	printf("\n");
	printArr(arr, n);
	return 0;
}
