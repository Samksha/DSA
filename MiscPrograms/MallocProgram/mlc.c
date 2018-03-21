#include"mlc.h"

void* myalloc(long size)
{
	char *buffer = (char *)malloc(size+sizeof(int));
	if(buffer == NULL) return NULL;
	heap_mem+=size;
	int *sizeBox = (int*)buffer;
	*sizeBox = size;
	return buffer + sizeof(int);
}

void myfree(void* temp)
{
	if(temp == NULL) return;

	char *buffer = (char*)temp - sizeof(int);
	int *sizeBox = (int*)buffer;
	heap_mem-=*sizeBox;
	free(buffer);
}

int getRand()
{
	srand(time(NULL));
	return ((rand()%15000)+10000);
}

int main()
{
	int m = getRand();
	printf("%d \n", m);
	int* arr = (int*)myalloc(m*sizeof(int));
	printf("%u %u %f\n", arr[0], arr[m-1], heap_mem);
	myfree(arr);
	printf("%f \n", heap_mem);
	/*
	struct Node* q = (struct Node*)myalloc(sizeof(struct Queue));
	struct Queue* q2 = (struct Queue*)myalloc(sizeof(struct Queue));
	printf("%f \n", heap_mem);
	myfree(q);
	printf("%f \n", heap_mem);
	*/
	return 0;
}
