#include"sort.h"

void seed()
{
	srand(time(NULL));
}

void swap(struct Empl* a, struct Empl* b)
{
	struct Empl temp = *a;
	*a = *b;
	*b = temp;
}


int partition(struct Empl** arr, int l, int r)
{
	int i, j;
	struct Empl* pivot = arr[l];
	struct Empl* temp = (struct Empl*)malloc(sizeof(struct Empl));
	i = l; 
	j = r+1;
	while(1)
	{
		do ++i; while(arr[i]->empID <= pivot->empID && i<=r);
		do --j; while(arr[j]->empID > pivot->empID);
		if(i >= j) break;
		swap(arr[i], arr[j]);
		/*
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp
		*/;
	}
	swap(arr[l], arr[j]);
	/*
	temp = arr[l];
	arr[l] = arr[j];
	arr[j] = temp;
	*/
	return j;
}


void quickSortRec(struct Empl** arr, int l, int r)
{
	int j;
//	if(l<r)
	while(l<r)
	{
		int pivIndex = l+rand()%(r-l+1);
//		j = partition(arr, l, r, pivIndex);
		j = partition(arr, l, r);
		quickSortRec(arr, l, j-1);
//		quickSortRec(arr, j+1, r);
		l = j+1;
	}
}

/*
int partition(struct Empl** arr, int l, int h, int p)
{
	struct Empl* pivot = arr[p];
	int i = l-1, j;
	swap(arr[p], arr[h]);
	for(j=l; j<=h-1; j++)
		if(arr[j]->empID <= pivot->empID)
			{
				i++;
				swap(arr[i], arr[j]);
			}
	swap(arr[i+1], arr[h]);
	return i+1;
}
*/

/*
int partition(struct Empl** arr, int l, int h, int p)
{
//	int pivotIndex = l+rand()%(h-l+1);
	swap(arr[p], arr[l]);
	struct Empl* pivot = arr[l];
	int i = l+1, j = h;
	while(i<j)
	{
		for(; i<=h && arr[i]->empID <= pivot->empID; i++);
		for(; arr[j]->empID > pivot->empID; j--);
		if(i<j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	int pos;
	if(i==j)
		pos = i;
	else
		pos = i-1;
	swap(arr[l], arr[pos]);
	return pos;
}
*/

/*
void quickSortRec(struct Empl** arr, int l, int h)
{
	if(l<h)
//	while(l<h)
	{
		int pivIndex = l+rand()%(h-l);
		int p = partition(arr, l, h, pivIndex);

//		printf("\n %d %d %d ", l, pivIndex, h);

		quickSortRec(arr, l, p-1);
		quickSortRec(arr, p, h);
//		l = p+1;
	}
}
*/

void quickSortIter(struct Empl** arr, int l, int h)
{
	int stack[h-l+1];
	int top = -1;
	stack[++top] = l;
	stack[++top] = h;
	while(top>=0)
	{
		h = stack[top--];
		l = stack[top--];
		int pivIndex = l+rand()%(h-l+1);
//		int p = partition(arr, l, h, pivIndex);
		int p = partition(arr, l, h);
		if(p-1 > l)
		{
			stack[++top] = l;
			stack[++top] = p-1;
		}
		if(p+1 < h)
		{
			stack[++top] = p+1;
			stack[++top] = h;
		}
	}
}

void quickSort(struct Empl** arr, int l, int h, int s)
{
	if(s<5)
	{
		insertionSort(arr, h-l+1);
	}
	else
	{
		quickSortRec(arr, l,  h);
//		quickSortIter(arr, l, h);
	}
}

struct Empl** createArr(int n)
{
	struct Empl** temp = (struct Empl**)malloc(sizeof(struct Empl*)*(n+1));
	for(int i = 0; i <= n; i++)
	{
		temp[i] = (struct Empl*)malloc(sizeof(struct Empl));
		temp[i]->name = (char*)malloc(sizeof(char)*10);
		temp[i]->empID = -1;
	}
	return temp;
}

void read(FILE* fp, struct Empl** arr)
{
	int i = 0;
//	while(!feof(fp))
	while(i<10)
	{
		fscanf(fp, "%s %ld\n", arr[i]->name, &arr[i]->empID);
		i++;
	}
}

void printArr(struct Empl** arr, int n)
{
	for(int i=0; i<n; i++)
		printf("%s %ld \n", arr[i]->name, arr[i]->empID);
}
