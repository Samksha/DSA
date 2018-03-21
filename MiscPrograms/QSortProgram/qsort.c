#include"qsort.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int l, int h)
{
	int i, j;
	int pivot = arr[h];

	i = l-1;
	
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

void quicksort(int* arr, int l, int h)
{
	if(l<h)
	{
		int pi = partition(arr, l, h);
		quicksort(arr, l, pi-1);
//		quicksort(arr, pi+1, h);
		l = pi+1;
	}
}

void printArr(int* arr, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {1,4,5,2,3,6};
	quicksort(arr, 0, 5);
	printArr(arr, 6);
	return 0;
}
