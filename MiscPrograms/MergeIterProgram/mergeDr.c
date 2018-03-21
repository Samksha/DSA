#include"merge.h"

extern long heap_mem;

int main()
{
	
	FILE* fp;
	fp = fopen("10240.txt", "r");
//	ftemp = fopen("temp.txt", "w");
	int n = 1024;
	int size = 10240;
	int i=0;
	FILE* tempfiles[size/n + 1];
	struct Element** l = createArray(n);
	while(i<=size/n)
	{
		char filename[20];
		sprintf(filename, "temp%d.txt", i);
		tempfiles[i] = fopen(filename, "w");
		readLarge(fp, l, n);
//		read(fp, l);
		mergeSortRekt(l, 0, n-1);
		printRecArrFile(l, n, tempfiles[i]);
		size-=n;
		i++;
	}
	fclose(fp);
/*	
	read(fp, l);
	printRecArr(l, n);
//	mergeSortRekt(l, 0, n-1);
	printf("HEAP MEMORY = %ld\n\n", heap_mem);
	mergeSortIter(l, 0, n);
	printf("\n");
	printRecArr(l, n);
	printf("HEAP MEMORY = %ld\n\n", heap_mem);
*/	
	/*
	int arr[] = {0, 8, 7, 9, 8, 2};
	int n = 6;
	printArr(arr, n);
	mergeSortInt(arr, 0, n-1);
	printArr(arr, n);
	*/
	return 0;
}	
