#include"sort.h"

void insertInOrder(struct Empl** arr, struct Empl* key, int size)
{
	int i = 0;
	for(; i<size; i++)
		if(key->empID < arr[i]->empID) break;
	int j = i;
	int k = size;
	for(; k>i; k--)
		arr[k] = arr[k-1];
	arr[j] = key;
}

void insertionSort(struct Empl** arr, int size)
{
	int i;
	for(i=0; i<size; i++)
		insertInOrder(arr, arr[i], i);
}
