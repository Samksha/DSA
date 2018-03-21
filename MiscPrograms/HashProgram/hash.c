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
