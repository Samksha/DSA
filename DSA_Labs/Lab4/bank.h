#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Record
{
	double cardNo;
	char* code;
	char* expDate;
	char* fName;
	char* lName;
};

struct Record newRec();
void read(FILE* f, struct Record* r);
void printRec(struct Record* r);
void insertInOrder(struct Record* r, struct Record* key, int size);
void insertionSort(struct Record* arr, int size);
