#include"qsort.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int l, int h)
{
//	int pivot = arr[h];
	int pivotIndex = l+rand()%(h-l+1);
	int pivot = arr[pivotIndex];
	int i = l-1, j;
	swap(&arr[pivotIndex], &arr[h]);
	for(j = l; j <= h-1; j++)
	{
		if(arr[j] <= pivot)
		{	
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[h]);
	return i+1;
}

int medPartition(int* arr, int l, int h, int k)
{
	if(h-l+1 <= 5)
	{
//		quickSort(arr, l, h);
		return l+k-1;
	}
	for(int i = 0; i < (h+1)/5; i++)
	{
		int left = 5*i;
		int right = left+4;
		if(right>h) right = h;
		int median = medPartition(arr, 5*i, 5*i+4, 3);
		swap(&arr[median], &arr[i]);
	}
	return medPartition(arr, 0, (h+1)/5, (h+1)/10);
}

/*
void quickSort(int* arr, int l, int h)
{
	if(l<h)	
	{
		int pi = partition(arr, l, h);
		quickSort(arr, l, pi-1);
		quickSort(arr, pi, h);
	}
}
*/

int* createArr(int n)
{
	int* temp = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++)
		temp[i] = rand()%1000;
	return temp;
}

void printArr(int* arr, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void seed()
{
	srand(time(NULL));
}
