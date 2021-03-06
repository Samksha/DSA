#include"heap.h"

void seed()
{
	srand(time(NULL));
}

void printArr(int* arr, int n)
{
	for(int i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int* arr, int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<n && arr[l]>arr[largest])
		largest = l;
	if(r<n && arr[r]>arr[largest])
		largest = r;
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int* arr, int n)
{
	for(int i = n/2 -1; i>=0; i--)
		heapify(arr, n, i);
	for(int i = n-1; i>=0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	seed();
	int n = rand()%20;
	int* arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i<n; i++)
		arr[i] = rand()%200;
	printArr(arr, n);
	heapSort(arr, n);
	printArr(arr, n);
	return 0;
}
