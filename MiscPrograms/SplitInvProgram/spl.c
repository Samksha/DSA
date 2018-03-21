#include"spl.h"

int* createArr(int num)
{
	int* arr = (int*)malloc(num*sizeof(int));
	return arr;
}

void printArr(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void getRand(int* arr, int size)
{
	srand(time(NULL));
	int i;
	for(i=0; i<size; i++)
		arr[i] = rand()%size;
}

int merge(int* arr, int l, int m, int r)
{
	int i,j,k;
	int count=0;
	int n1 = m-l+1;
	int n2 = r-m;
	
	int L[n1], R[n2];

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
			arr[k++]=L[i++];
		else
		{
			arr[k++]=R[j++];
			count = count+(m-i+1);
		}
	}

	while(i<n1)
		arr[k++]=L[i++];
	while(i<n2)
		arr[k++]=R[j++];
	return count;
}

int mergeSort(int* arr, int l, int r)
{
	int count=0;
	if(l<r)
	{
		int m = (l+r)/2;
		
		count += mergeSort(arr, l, m);
		count += mergeSort(arr, m+1, r);
		
		count += merge(arr, l, m, r); 
	}
	return count;
}

