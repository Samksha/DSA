#include"bank.h"

struct Record newRec()
{
	struct Record* r = (struct Record*)malloc(sizeof(struct Record));
	r->expDate = (char*)malloc(7*sizeof(char));
	r->code = (char*)malloc(5*sizeof(char));
	r->fName = (char*)malloc(5*sizeof(char));
	r->lName = (char*)malloc(5*sizeof(char));
	return *r;
}

void read(FILE *f, struct Record* r)
{
//	char c;
	int i = 0;
	while(!feof(f))
	{
//		while(fgets(line, 100, f))
//		fscanf(f, "\"%lf,%[^,],%[^,],%[^,],%[^\"]\"\n", &r[i]->cardNo, r[i]->code, r[i]->expDate, r[i]->fName, r[i]->lName);
		fscanf(f, "\"%lf,%[^,],%[^,],%[^,],%[^\"]\"\n", &r[i].cardNo, r[i].code, r[i].expDate, r[i].fName, r[i].lName);
//		printf("%s", line);
		i++;
	}
}

void printRec(struct Record* r)
{
	printf("%lf, %s, %s, %s, %s\n", r->cardNo, r->code, r->expDate, r->fName, r->lName);
}

void insertInOrder(struct Record* arr, struct Record* key, int size)
{
	arr = (struct Record*)realloc(arr,(size+1)*sizeof(struct Record));
	int i = 0;
	/*while(arr[i].cardNo < key->cardNo)
		i++;*/
	for(i=0; i<size; i++)
		if(key->cardNo > arr[i].cardNo) break;
	int j = i;
	int k = size;
	for(; k>i; k--)
		arr[k] = arr[k-1];
	/*while(i<size+2)
	{
		arr[i+1]=arr[i];
		i++;
	}*/
	arr[j] = *key;
}

void insertionSort(struct Record* arr, int size)
{
	struct Record* temp = (struct Record*)malloc(sizeof(struct Record));
//	struct Record* temp = &arr[0];
//	struct Record* temp = (struct Record*)malloc(size*sizeof(struct Record));
	int i;
/*	for(i=0; i<size; i++)
		temp[i] = newRec();*/
	for(i=0; i<size; i++)
		insertInOrder(temp, &arr[i], i);
	printf("\n");
	for(i=0; i<size; i++)
		printRec(&temp[i]);
}
