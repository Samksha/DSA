#include"matrix.h"

const int MAX = 100;
long heap_mem = 0;

void* myalloc(long size)
{
	char* buffer = (char*)malloc(sizeof(int)+size);
	if(buffer == NULL) return NULL;
	heap_mem+=size;
	int *sizeBox = (int*)buffer;
	*sizeBox = size;
	return buffer+sizeof(int);
}

void myfree(void* temp)
{
	if(temp == NULL) return;
	char* buffer = (char*)temp - sizeof(int);
	int *sizeBox = (int*)buffer;
	heap_mem -= *sizeBox;
	free(buffer);
}

int** createArr(int row, int col)
{
	int** temp = (int**)malloc(row*sizeof(int*));
	for(int i=0; i<row; i++)
	{
		temp[i] = (int*)malloc(col*sizeof(int));
		for(int j=0; j<col; j++)
			temp[i][j] = 0;
	}
	return temp;
}

void multiplyMatrixRec(int row1, int col1, int** A, int row2, int col2, int** B, int** C)
{
	static int i = 0, j = 0, k = 0;
	if(i>=row1) return;
	if(j<col2)
	{
		if(k<col1)
		{
			C[i][j] += A[i][k]*B[k][j];
			k++;
			multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
		}
		k = 0;
		j++;
		multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
	}
	j = 0;
	i++;
	multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
}

void printArr(int** arr, int row, int col)
{
	int i, j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}

}

void multiplyMatrix(int row1, int col1, int** A, int row2, int col2, int** B)
{
	if(row2 != col1) return;
	int** C = createArr(row2, col1);
	printArr(C, row2, col1);
	multiplyMatrixRec(row1, col1, A, row2, col2, B, C);
	printArr(C, row2, col1);
}
