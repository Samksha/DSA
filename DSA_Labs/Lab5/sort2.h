#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* myalloc(long size);
void myfree(void* temp);
struct Element
{
	char* name;
	float cgpa;
};
struct Element newEle();
void read(FILE* fp, struct Element* l);
void printRec(struct Element* ele);
void merge(struct Element* ls1, int sz1, struct Element* ls2, int sz2, struct Element* ls);
//void merge(struct Element* ls, int l, int m, int h);
void mergeSortRec(struct Element* ls, int l, int h);
void mergeSortIter(struct Element* ls, int sz);
void mergeSortInt(int* arr, int l, int h);
