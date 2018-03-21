#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element
{
	char* name;
	float cgpa;
};

void read(FILE* fp, struct Element** arr);
void printArr(struct Element** arr, int n);
struct Element** createArr(int n);
