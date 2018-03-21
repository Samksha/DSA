#include"bsort.h"

void bucketSort(int* arr, int n)
{
	int i, j, k;
	int buckets[n];
	memset(buckets, 0, sizeof(buckets));

//	for(i=0; i<n; i++)
//		buckets[i] = 0;
	
	for(i=0; i<n; i++) 
		(buckets[arr[i]])++;

	for(i=0, j=0; j<n; ++j) 
		for(k = buckets[j]; k>0; --k)
			arr[i++] = j;
}

void printArr(int* arr, int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {4, 5, 1, 4, 3, 2, 2};
	int n = 7;
	bucketSort(arr, 7);
	printArr(arr, n);
	return 0;
}
