#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct Element
{
	char* name;
	float cgpa;
};

void* myalloc(long size);
void myfree(void* temp);
struct Element** createArray(int size);
void mergeInt(int* arr, int l, int m, int h);
void mergeSortInt(int* arr, int l, int h);
void printArr(int* arr, int size);
void readLarge(FILE* fp, struct Element** l, int n);
void read(FILE* fp, struct Element** l);
void printRecArr(struct Element** l, int size);
struct Element* newRec();
void mergeSortRec(struct Element** arr, int l, int h);
void merge(struct Element** arr, int l, int m, int h);
void mergeSortRekt(struct Element** arr, int l, int h);
void mergeRekt(struct Element** arr1, int sz1, struct Element** arr2, int sz2, struct Element** arr);
int min(int x, int y);
void mergeSortIter(struct Element** arr, int l, int h);
void printRecArrFile(struct Element** arr, int n, FILE* ftemp);
