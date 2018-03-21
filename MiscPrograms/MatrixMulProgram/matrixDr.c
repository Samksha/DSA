#include"matrix.h"

extern const int MAX;

int main()
{
	int row1 = 3, col1 = 3, row2 = 3, col2 = 3;
	int** A = createArr(row1, col1); 
	int** B = createArr(row2, col2);
	srand(time(NULL));
	for(int i=0; i<row1; i++)
		for(int j=0; j<col1; j++)
		{	
			A[i][j] = rand()%10;
			B[i][j] = rand()%10;
		}
	printArr(A, row1, col1);
	printArr(B, row2, col2);
	multiplyMatrix(row1, col1, A, row2, col2, B);
	return 0;
}
