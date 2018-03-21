#include <stdio.h>
#include <stdlib.h>

void* myalloc(long size);
void myfree(void* temp);

struct Element
{
	char* name;
	float cgpa;
};

struct Element* newEle();
//void merge(struct Element* L1, int sz1, struct Element* L2, int sz2, struct Element* L3);
void read(FILE* fp, struct Element* l);
void printRec(struct Element* ele);
