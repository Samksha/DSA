#include"shell.h"

void shellSort(int* arr, int n)
{
	for(int gap=n/2; gap>0; gap/=2)
		for(int i=gap; i<n; i++)
		{
			int temp = arr[i];
			int j;
			for(j=i; j>=gap && arr[j-gap]>temp; j-=gap)
				arr[j] = arr[j-gap];
			arr[j] = temp;
		}
}

void printArr(int* arr, int n)
{
	for(int i = 0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {12, 34, 54, 2, 3}, i;
	int n = sizeof(arr)/sizeof(arr[0]);
	shellSort(arr, n);
	printArr(arr, n);
	return 0;
}