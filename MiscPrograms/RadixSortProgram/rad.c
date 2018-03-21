#include"rad.h"

void seed()
{
	srand(time(NULL));
}

void printArr(int* arr, int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int getMax(int* arr, int n)
{
	int max = arr[0];
	for(int i=0; i<n; i++)
		if(arr[i] > max)
			max = arr[i];
	return max;
}

void countSort(int* arr, int n, int exp)
{
	int* output = (int*)malloc(sizeof(int)*n);
	int i, count[10] = {0};
	
	for(i=0; i<n; i++)
		count[ (arr[i]/exp)%10 ]++;
	
	for(i=1; i<10; i++)
		count[i] += count[i-1];

	for(i=n-1; i>=0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] -1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}
	
	for(i=0; i<n; i++)
		arr[i] = output[i];
}

void radixSort(int* arr, int n)
{
	int m = getMax(arr, n);
	for(int exp = 1; m/exp>0; exp*=10)
		countSort(arr, n, exp);
}

int main()
{
	seed();
	int n = rand()%20;
	int* arr = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i<n; i++)
		arr[i] = rand()%100;
//	int arr[] = {231, 1421, 412, 411, 244, 44};
//	int n = sizeof(arr)/sizeof(arr[0]);
	radixSort(arr, n);
	printArr(arr, n);
	return 0;
}
