#include"heap.h"

heapNode createNode(char data, int freq)
{
	heapNode h = (heapNode)malloc(sizeof(struct _heapNode));
	h->data = data;
	h->freq = freq;
	h->left = NULL;
	h->right = NULL;
	return h;
}

minHeap createMinHeap(int capacity)
{
	minHeap h = (minHeap)malloc(sizeof(struct _minHeap));
	h->capacity = capacity;
	h->size = 0;
	h->arr = (heapNode*)malloc(sizeof(heapNode));
	return h;
}

void swapMinHeapNodes(heapNode* a, heapNode* b)
{
	heapNode temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(minHeap h, int idx)
{
	int smallest = idx;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	if(left < h->size && h->arr[left]->freq < h->arr[smallest]->freq)
		smallest = left;
	if(right < h->size && h->arr[right]->freq < h->arr[smallest]->freq)
		smallest = right;
	if(smallest != idx)
	{
		swapMinHeapNodes(&h->arr[smallest], &h->arr[idx]);
		minHeapify(h, smallest);
	} 
}

int isSizeOne(minHeap h)
{
	return h->size==1;
}

heapNode extractMin(minHeap h)
{
	heapNode temp = h->arr[0];
	h->arr[0] = h->arr[h->size-1];
	--h->size;
	minHeapify(h, 0);
	return temp;
}

void insertMinHeap(minHeap h, heapNode n)
{
	int i = h->size;
	++h->size;
	while(i && n->freq < h->arr[(i-1)/2]->freq)
	{
		h->arr[i] = h->arr[(i-1)/2];
		i = (i-1)/2;
	}
	h->arr[i] = n;
}

void buildMinHeap(minHeap h)
{
	int n = h->size-1;
	int i;
	for(i = (n-1)/2; i>=0; --i)
		minHeapify(h, i);
}

void printArr(int arr[], int n)
{
	int i;
	for(i=0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int isLeaf(heapNode root)
{
	return !(root->left) && !(root->right);
}

minHeap createAndBuildMinHeap(char* data, int* freq, int size)
{
	minHeap h = createMinHeap(size);
	for(int i = 0; i < size; i++)
		h->arr[i] = createNode(data[i], freq[i]);
	h->size = size;
	buildMinHeap(h);
	return h;
}

