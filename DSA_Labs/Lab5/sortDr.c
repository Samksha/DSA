#include"sort2.h"

//extern long heap_mem;

int main()
{
	int i;
	FILE* fp;
	fp = fopen("1024.txt", "r");
	struct Element* l = (struct Element*)malloc(10*sizeof(struct Element));
	for(i=0; i<10; i++)
		l[i] = newEle();
	read(fp, l);
	for(i=0; i<10; i++)
		printRec(&l[i]);
	mergeSortRec(l, 0, 10);
	printf("\n");
	for(i=0; i<10; i++)
		printRec(&l[i]);
/*	int arr[] = {0, 9, 12, 1, 2, 4, 6, 3, 7, 10};
	int n = 10;
	mergeSortInt(arr, 0, n-1);*/
	fclose(fp);
	return 0;
}
