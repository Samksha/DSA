#include"hash.h"

int h1(char* s, int baseNumber, int tableSize)
{
	int sum = 0;
	for(int i = 0; i < strlen(s); i++)
		sum+=s[i];
	return (sum%baseNumber)%tableSize;
}

int collCount(char** s, int baseNumber, int tableSize)
{
	int count = 0, hashKey;
	int* hashTable = (int*)malloc(sizeof(int)*tableSize);
	for(int i = 0; s[i]!=NULL; i++)
	{
		hashKey = h1(s[i], baseNumber, tableSize);
		if(hashTable[hashKey] == 1)
			count++;
		else
			hashTable[hashKey] = 1;
	}	
	return count;
}

int chkValid(char* s)
{
	for(int i = 0; i < strlen(s); i++)
		if(!isalpha(s[i]))
			return 1;
	return 0;
}

char** parseFile(FILE* fp)
{
	int valCount = 0;
	char** arr = (char**)malloc(sizeof(char*));
	arr[0] = (char*)malloc(sizeof(char)*20);
	char* temp = (char*)malloc(sizeof(char)*20);
	while(!feof(fp))
//	for(int i = 0; i < 4; i++)
	{
		fscanf(fp, "%s ", temp);
		if(chkValid(temp)==0)
		{
			valCount++;
			arr = (char**)realloc(arr, sizeof(char*)*(valCount));
			arr[valCount-1] = (char*)malloc(sizeof(char)*20);
			strcpy(arr[valCount-1], temp);
		}
	}
	printf("Number of valid strings = %d\n", valCount);
	return arr;
}

void printStrings(char** arr)
{
	for(int i = 0; arr[i]!=NULL; i++)
		printf("%s\n", arr[i]);
}

struct HTable* createHashTable(int tableSize)
{
	struct HTable* ht = (struct HTable*)malloc(sizeof(struct HTable));
	ht->table = (struct LList*)malloc(sizeof(struct LList)*tableSize);
	ht->elementCount = 0;
	ht->insertionCost = 0;
	ht->queryingCost = 0;
	return ht;
}

void insert(struct HTable* ht, char** A, int j, int baseNumber, int tableSize)
{
	int hash = h1(A[j], baseNumber, tableSize);

	if(ht->table[hash].head->count == 0)
	{
		ht->table[hash].head->index = j;
		ht->table[hash].tail = ht->table[hash].head;
		ht->table[hash].head->count++;
		ht->elementCount++;
	}
	else
	{
//		int flag = 0;
		struct Node* temp = ht->table[hash].head;
		while(temp->next != NULL)
		{
			if(strcmp(A[temp->index], A[j])==0)
			{
				temp->count++;
				return;
			} 
			temp = temp->next;
		}
		temp->next = (struct Node*)malloc(sizeof(struct Node));
		temp->next->next = NULL;
		temp->next->index = j;
		temp->next->count = 1;
		ht->insertionCost++;
	}
}

int insertAll(struct HTable* ht, char** A, int baseNumber, int tableSize)
{
	for(int i = 0; A[i]!=NULL; i++)
		insert(ht, A, i, baseNumber, tableSize);
	return ht->insertionCost;
}


