#include"sort2.h"

long heap_mem=0;

void* myalloc(long size)
{
	char* buffer = (char*)malloc(size+sizeof(int));
	if(buffer == NULL) return NULL;

	heap_mem += size;
	int* sizeBox = (int*)buffer;
	*sizeBox = size;
	return buffer+sizeof(int);
}

void myfree(void* temp)
{
	if(temp == NULL) return;
	char* buffer = (char*)temp - sizeof(int);
	int* sizeBox = (int*)buffer;
	heap_mem -= *sizeBox;
	free(buffer);
}

struct Element newEle()
{
	struct Element* temp = (struct Element*)myalloc(sizeof(struct Element));
	temp->name = (char*)myalloc(10*sizeof(char));
	temp->cgpa = 0;
	return *temp;
}

void read(FILE* fp, struct Element* l)
{
	int i = 0;
//	while(!feof(fp))
	for(i=0; i<10; )
	{
		fscanf(fp, "%[^,],%f\n", l[i].name, &l[i].cgpa);
		i++;
	}
}

void printRec(struct Element* ele)
{
	printf("%s, %f\n", ele->name, ele->cgpa);
}

void merge(struct Element* ls1, int sz1, struct Element* ls2, int sz2, struct Element* ls)
//void merge(struct Element* ls, int l, int m, int h)
{
//	printf("reached");
	int i, j, k;
	i=0;
	j=0;
	k=0;
	while(i<sz1 && j<sz2)
	{
		if(ls1[i].cgpa<ls2[j].cgpa)
			ls[k]=ls1[i++];
		else
			ls[k]=ls2[j++];
		k++;
	}
	while(i<sz1)
		ls[k++]=ls1[i++];
	while(j<sz2)
		ls[k++]=ls2[j++];

	printf("\n");
	for(i=0; i<sz1+sz2; i++)
		printRec(&ls[i]);
}

void mergeSortRec(struct Element* ls, int l, int h)
{
	int mid, sz1, sz2, i, j;
	if(l<h)
	{
		mid = ((l+h)/2);
		mergeSortRec(ls, l, mid);
		mergeSortRec(ls, mid+1, h);
//		printf("reached2");
		sz1 = mid-l+1;
		sz2 = h-l;
		struct Element* ls1 = (struct Element*)malloc(sz1*sizeof(struct Element));
		struct Element* ls2 = (struct Element*)malloc(sz2*sizeof(struct Element));
		struct Element* ls3 = (struct Element*)malloc((sz1+sz2)*sizeof(struct Element));
		for(i=0; i<sz1; i++)
		{
			ls1[i]=newEle();
			ls1[i]=ls[l+i];
		}
		for(j=0; j<sz2; j++)
		{
			ls2[j]=newEle();
			ls2[j]=ls[mid+1+j];
		}
		for(i=0; i<sz1+sz2; i++)
			ls3[i]=newEle();
		merge(ls1, sz1, ls2, sz2, ls3);
//		free(ls1);
//		free(ls2);
	}
}

void mergeSortIter(struct Element* ls, int sz)
{
//	int i,j;
//	for(i=0; i<sz; i*=2)
//		for(j=i; j<sz; j+=i*2)
}

void mergeInt(int* arr, int l, int m, int h)
{
	int sz1 = m-l+1;
	int sz2 = h-l;
//	int* temp1 = (int*)sizeof(sz1*sizeof(int));
//	int* temp2 = (int*)sizeof(sz2*sizeof(int));
	int temp1[sz1], temp2[sz2];
	int i, j, k;
	for(i=0; i<sz1;	i++)
		temp1[i] = arr[l+i];
	for(j=0; j<sz2; j++)
		temp2[j] = arr[m+1+j];
	
	i=0;
	j=0;
	k=l;
	while(i<sz1 && j<sz2)
	{
		if(temp1[i]<temp2[j])
			arr[k]=temp1[i++];
		else
			arr[k]=temp2[j++];
		k++;
	}
	while(i<sz1)
		arr[k++]=temp1[i++];
	while(j<sz2)
		arr[k++]=temp2[j++];
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
