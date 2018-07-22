#include <stdio.h>
#include <stdlib.h>

typedef struct _heapNode* heapNode;

struct _heapNode
{
	char data;
	int freq;
	heapNode left;
	heapNode right;
};

struct _minHeap
{
	int size;
	int capacity;
	heapNode* arr;	
};

typedef struct _minHeap* minHeap;

heapNode createNode(char data, int freq);
minHeap createMinHeap(int capacity);
void swapMinHeapNodes(heapNode* a, heapNode* b);
void minHeapify(minHeap h, int idx);
