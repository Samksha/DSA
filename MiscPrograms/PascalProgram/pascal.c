#include"pascal.h"

/*
void setPascal(int **pnumbers, int n)
{
	int line;
	for(line=1; line<=n; line++)
	{
		int C, i;
		C=1;
		for(i=1; i<=line; i++)
		{
			//printf("%d ", C);
			pnumbers[line-1][i-1]=C;
			C=C*(line-i)/i;
		}
		//printf("\n");
	}
}

int** createArray(int n)
{
	int **pnumbers = (int **)malloc(n*sizeof(int *));
	int i;
	for(i=0; i<n; i++)
		pnumbers[i] = (int *)malloc((i+1)*sizeof(int));
	return pnumbers;
}

void printArray(int **pnumbers, int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<=i; j++)
			printf("%d ", pnumbers[i][j]);
		printf("\n");
	}	
}

void freeArray(int **pnumbers, int n)
{
	int i;
	for(i=0; i<n; i++)
		free(pnumbers[i]);
	free(pnumbers);	
}
*/
int main()
{
	int n;
	scanf("%d", &n);
	int **pnumbers = createArray(n);
	setPascal(pnumbers, n);
	printArray(pnumbers, n);
	freeArray(pnumbers, n);
	return 0;
}
