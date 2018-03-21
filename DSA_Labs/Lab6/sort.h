#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Empl
{
	char* name;
	long empID;
};

struct Node
{
	struct Empl e;
	struct Node* next;
};

struct Stack
{
	struct Node* top;
	int size;
};

void seed();

struct Empl** createArr(int n);
void read(FILE* fp, struct Empl** arr);
void printArr(struct Empl** arr, int n);

void* myalloc(long size);
void myfree(void* temp);

void quickSort(struct Empl** arr, int l, int h, int s);
void quickSortRec(struct Empl** arr, int l, int h);
int partition(struct Empl** arr, int l, int r);
//int partition(struct Empl** arr, int l, int h, int p);
void swap(struct Empl* a, struct Empl* b);

void insertInOrder(struct Empl** arr, struct Empl* key, int size);
void insertionSort(struct Empl** arr, int size);
