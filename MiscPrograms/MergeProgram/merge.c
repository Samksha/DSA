#include"merge.h"

void merge(int *arr, int l, int m, int r)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	
	int L[n1], R[n2];

	//Copy into temp arrays	
	for(i=0; i<n1; i++)
		L[i] = arr[l+i];
	for(j=0; j<n2; j++)
		R[j] = arr[m+1+j];
	
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
			arr[k] = L[i++];
		else
			arr[k] = R[j++];
		k++;
	}

	while(i<n1)
		arr[k++] = L[i++];
	while(j<n2)
		arr[k++] = R[j++];
}

void mergeSort(int* arr, int l, int h)
{
	if(l < h)
	{
		int m = (l+r)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, h);
		merge(arr, l, m, h);
	}
}

void printArr(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {1,3,5,2,4,6};
	int n = 6;
	printArr(arr, 6);
	mergeSort(arr, 0, n-1);
	printArr(arr, 6);
	return 0;
}
