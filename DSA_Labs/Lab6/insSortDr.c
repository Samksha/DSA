#include"sort.h"

int main()
{
	int n = 10;
	struct Empl** arr = createArr(n);
	FILE* fp;
	fp = fopen("data.txt", "r");
	read(fp, arr);
	printArr(arr, n);
	insertionSort(arr, n);
	return 0;
}
