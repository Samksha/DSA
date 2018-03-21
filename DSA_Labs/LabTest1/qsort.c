#include "qsort.h"

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char* fileName)
{
	FILE* fp;
	fp = fopen(fileName, "r");
	int n, i=0;
	fscanf(fp, "%d\n", &n);
//	printf("%d\n", n);
	int* arr = (int*)malloc(sizeof(int)*n);
	while(!feof(fp))
		fscanf(fp, "%*s %d\n", &arr[i++]);
	fclose(fp);
	return arr;
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey)
{
	int i, j = 0;
	KeyStruct k = (KeyStruct)malloc(sizeof(struct keyStruct));
	k->Keys = (int*)malloc(sizeof(int)*(hiKey-loKey+1));
	k->keysSize=0;
	int buckets[hiKey-loKey+1];

	for(i = 0; i<hiKey-loKey+1; i++)
		buckets[i]=0;

	for(i = 0; i<lsSize; i++)
		buckets[Ls[i]-loKey]++;

	for(i = 0; i<hiKey-loKey+1; i++)
		if(buckets[i]!=0)
		{
			k->Keys[j] = loKey+i;
//			printf("%d ", k->Keys[j]);
			j++;
		}
	k->keysSize = j;
	return k;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int part2Loc(int* Ls, int lo, int hi, int piv)
{
	int k = Ls[piv];
	swap(&Ls[piv], &Ls[lo]);
	int md = lo, bdry = lo+1;
	while(bdry<=hi)
	{
		if(Ls[bdry] > k) bdry++;
		else
		{
			swap(&Ls[bdry], &Ls[md+1]);
			md++;
			bdry++;
		}
	}
	swap(&Ls[lo], &Ls[md]);
	return md;
}

void quickSortIter(int* Ls, int size)
{
	int l = 0, h = size-1;
	int stack[h-l+1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while(top>=0)
	{
		h = stack[top--];
		l = stack[top--];
		int piv = l+rand()%(h-l);
		int p = part2Loc(Ls, l, h, piv);
		if(p-1>l)
		{
			stack[++top] = l;
			stack[++top] = p-1;
		}
		if(p+1<h)
		{
			stack[++top] = p+1;
			stack[++top] = h;
		}
	}
}

int* bucketSort(int* Ls, int lsSize, int loKey, int hiKey)
{
	int i;
	int* buckets = (int*)malloc(sizeof(int)*(hiKey-loKey+1));
	int* arr = (int*)malloc(sizeof(int)*(hiKey-loKey+1));

	for(i = 0; i<hiKey-loKey+1; i++)
		buckets[i]=0;

	for(i = 0; i<lsSize; i++)
		buckets[Ls[i]-loKey]++;

	return buckets;
}

void quickSortKnownKeyRange(int* Ls, int size, int loKey, int hiKey)
{
	int j = 0;
	KeyStruct k = extractKeys(Ls, size, loKey, hiKey);
	quickSortIter(k->Keys, k->keysSize);
	int* buckets = bucketSort(Ls, size, loKey, hiKey);
	for(int i = 0; i<hiKey-loKey+1; i++)
	{
		while(buckets[k->Keys[i]-loKey]>0)
		{
			Ls[j++] = k->Keys[i];
			buckets[k->Keys[i]-loKey]--;
		}
	}
}
