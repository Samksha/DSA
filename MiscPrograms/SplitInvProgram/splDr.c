#include"spl.h"

int main()
{
//	int *arr = createArr(10);
//	getRand(arr, 10);
	int arr[] = {1,3,5,2,4,6};
	printArr(arr, 6);
	int count = mergeSort(arr, 0, 5);
	printArr(arr, 6);
	printf("%d \n", count);
	return 0;
}
