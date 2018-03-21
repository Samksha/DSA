#include"csort.h"

void printArr(char* arr, int n)
{
	for(int i = 0; i<n; i++)
		printf("%c ", arr[i]);
	printf("\n");
}

void countSort(char* arr)
{
	char* output = (char*)malloc(strlen(arr)*sizeof(char));
	int count[256], i;
	memset(count, 0, sizeof(count));	

	for(i=0; arr[i]; ++i) ++count[arr[i]];

//	printArr(count, sizeof(count)/sizeof(count[0]));

 	for(i=1; i<=255; ++i) count[i] += count[i-1];

	for(i=0; arr[i]; ++i)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}
	
	printArr(output, strlen(arr));

	for(i=0; arr[i]; ++i) arr[i] = output[i];
}

int main()
{
	char arr[] = "tyasdgrssample";
	countSort(arr);
	printf("%s\n", arr);
	return 0;
}
