#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

struct Node
{
	int index;
	int count;
	struct Node* next;
};

struct LList
{
	struct Node* head;
	struct Node* tail;
	int hashVal;
};

struct HTable
{
	struct LList* table;
	int elementCount;
	int insertionCost;
	int queryingCost;
};

int h1(char* s, int baseNumber, int tableSize);
int collCount(char** s, int baseNumber, int tableSize);
int chkValid(char* s);
char** parseFile(FILE* fp);
void printStrings(char** arr);

struct HTable* createHashTable(int tableSize);
void insert(struct HTable* ht, char** A, int j, int baseNumber, int tableSize);
int insertAll(struct HTable* ht, char** a, int baseNumber, int tableSize);
