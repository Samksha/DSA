#include"merge.h"

long heap_mem=0;

void* myalloc(long size)
{
	char* buffer = (char*)malloc(sizeof(int)+size);
	if(buffer == NULL) return NULL;
	
	heap_mem+=size;
	int* sizeBox = (int*)buffer;
	*sizeBox = size;
	return buffer+sizeof(int);
}

void myfree(void* temp)
{
	if(temp == NULL) return;
	
	char* buffer = (char*)temp - sizeof(temp);
	int* sizeBox = (int*)buffer;
	heap_mem-=*sizeBox;
	free(buffer);
}

struct Element** createArray(int size)
{
	struct Element** temp = (struct Element**)myalloc(size*sizeof(struct Element*));
	int i;
	for(i=0; i<size; i++)
		temp[i] = newRec();
	return temp;
}

void read(FILE* fp, struct Element** l)
{
	int i;
	i=0;
	while(!feof(fp))
//	for(; i<10; )
	{
		fscanf(fp, "%[^,],%f\n", l[i]->name, &l[i]->cgpa);
		i++;
	}
}

void readLarge(FILE* fp, struct Element** l, int n)
{
	int i;
	i=0;
	for(;i<1024 || feof(fp);)
//	while(i<n)
//	while(!feof(fp)&&i<n)
	{
		fscanf(fp, "%[^,],%f\n", l[i]->name, &l[i]->cgpa);
		i++;
	}
}

void printRecArr(struct Element** l, int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%s, %f\n", l[i]->name, l[i]->cgpa);
//	printf("\n");
}

struct Element* newRec()
{
	struct Element* temp = (struct Element*)myalloc(sizeof(struct Element));
	temp->name = (char*)myalloc(sizeof(char)*10);
	temp->cgpa = 0;
	return temp;
}

void merge(struct Element** arr, int l, int m, int h)
{
	int i,j,k;
	int sz1 = m-l+1;
	int sz2 = h-m;
	struct Element** ls1 = (struct Element**)myalloc(sz1*sizeof(struct Element*));
	struct Element** ls2 = (struct Element**)myalloc(sz2*sizeof(struct Element*));

	for(i=0; i<sz1; i++)
		ls1[i] = arr[l+i];
	for(j=0; j<sz2; j++)
		ls2[j] = arr[m+1+j];

	i = 0;
	j = 0;
	k = l;
	while(i<sz1 && j<sz2)
	{
		if(ls1[i]->cgpa < ls2[j]->cgpa)
			arr[k] = ls1[i++];
		else
			arr[k] = ls2[j++];
		k++;
	}
	while(i<sz1)
		arr[k++] = ls1[i++];
	while(j<sz2)
		arr[k++] = ls2[j++];
}

void mergeSortRec(struct Element** arr, int l, int h)
{
	int mid;
	if(l<h)
	{
		mid = (l+h)/2;
		mergeSortRec(arr, l, mid);
		mergeSortRec(arr, mid+1, h);
		merge(arr, l, mid, h);
	}
}

void mergeRekt(struct Element** arr1, int sz1, struct Element** arr2, int sz2, struct Element** arr)
{
	int i,j,k;
	i=0;
	j=0;	
	k=0;
	while(i<sz1 && j<sz2)
	{
		if(arr1[i]->cgpa < arr2[j]->cgpa)
			arr[k] = arr1[i++];
		else
			arr[k] = arr2[j++];
		k++;
	}
	while(i<sz1)
		arr[k++] = arr1[i++];
	while(j<sz2)
		arr[k++] = arr2[j++];
}

void mergeSortRekt(struct Element** arr, int l, int h)
{
	int mid, i, j, k;
	if(l<h)
	{
		mid = (l+h)/2;
		mergeSortRekt(arr, l, mid);
		mergeSortRekt(arr, mid+1, h);
		int sz1 = mid-l+1;
		int sz2 = h-mid;
/*		struct Element** arr1 = (struct Element**)malloc(sz1*sizeof(struct Element*));
		struct Element** arr2 = (struct Element**)malloc(sz2*sizeof(struct Element*));
		for(i=0; i<sz1; i++)
			arr1[i] = arr[l+i];
		for(j=0; j<sz2; j++)
			arr2[j] = arr[mid+1+j];
*/  
		struct Element** temp = (struct Element**)myalloc((sz1+sz2)*sizeof(struct Element*));
		mergeRekt(arr+l, sz1, arr+mid+1, sz2, temp);
		for(k=0; k<sz1+sz2; k++)
			arr[l+k] = temp[k];
//		myfree(temp);
	}
}

void mergeSortIter(struct Element** arr, int l, int h)
{
	int n = h-l;
	int curr_size, left_index, k, mid, right_index;
	for(curr_size=1; curr_size<n; curr_size=2*curr_size)
	{
		for(left_index=0; left_index<n-1; left_index+=2*curr_size)
		{
			mid = left_index+curr_size-1;
			right_index = min(left_index + 2*curr_size-1, n-1);
			//merge(arr, left_index, mid, right_index);
			
			int sz1 = mid-left_index+1;
			int sz2 = right_index-mid;
			struct Element** temp = (struct Element**)myalloc((sz1+sz2)*sizeof(struct Element*));
			mergeRekt(arr+left_index, sz1, arr+mid+1, sz2, temp);
			
			for(k=0; k<sz1+sz2; k++)
				arr[left_index+k] = temp[k];
			//free(temp);	
		}
	}
}

void mergeInt(int* arr, int l, int m, int h)
{
	int sz1 = m-l+1;
	int sz2 = h-m;
//	int L[sz1], R[sz2];
	
	int* L = (int*)myalloc(sz1*sizeof(int));	
	int* R = (int*)myalloc(sz2*sizeof(int));

	int i,j,k;
	
	for(i=0; i<sz1; i++)
		L[i] = arr[l+i];
	for(j=0; j<sz2; j++)
		R[j] = arr[m+1+j];

	i=0;
	j=0;
	k=l;
	while(i<sz1 && j<sz2)
	{
		if(L[i]<R[j])
			arr[k]=L[i++];
		else
			arr[k]=R[j++];
		k++;
	}

	while(i<sz1)
		arr[k++]=L[i++];
	while(j<sz2)
		arr[k++]=R[j++];
}

void mergeSortInt(int* arr, int l, int h)
{
	int mid;
	if(l<h)
	{
		mid = (l+h)/2;
		mergeSortInt(arr, l, mid);
		mergeSortInt(arr, mid+1, h);
		mergeInt(arr, l, mid, h);
	}
}

void printArr(int* arr, int size)
{
	for(int i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void printRecArrFile(struct Element** arr, int n, FILE* ftemp)
{
	int i;
	for(i=0; i<n; i++)
	{
		fprintf(ftemp, "%f\n", arr[i]->cgpa);
	}
}

int min(int x, int y)
{
	return (x<y)?x:y;
}
