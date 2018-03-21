#include"hash.h"

int h1(char* s, int baseNumber, int tableSize)
{
	int sum = 0;
	int n = strlen(s);
	while(n-->0)
	{
		sum+=s[n];
//		printf("%d ", s[n]);
	}
//	printf("\n%d ", sum);
	return (sum%baseNumber)%tableSize;
//	return 0;
}

int collisionCount(char** arr, int n, int baseNumber, int tableSize)
{
	int* table = (int*)malloc(sizeof(int)*tableSize);
	int count = 0;
	printf("Size = %d\n", n);
	while(n-->0)
	{
		int hVal = h1(arr[n], baseNumber, tableSize);
		if(table[hVal] == 1)
			count++;
		else
			table[hVal] = 1;
	}
//	printf("%d ", n);
	return count;
}

char** parseFile(FILE* fp)
{
	char** validStr = NULL;
	char* str = (char*)malloc(sizeof(char)*20);
	int count = 0;
	for(;!feof(fp);)
	{
		if(feof(fp)) break;
 		fscanf(fp, "%s", str);
//		printf("%s ", str);
		if(chkValid(str)==0)
		{
			count++;
			validStr = (char**)realloc(validStr, sizeof(char*)*(count));
			validStr[count-1] = (char*)malloc(sizeof(char)*strlen(str));
			strcpy(validStr[count-1], str);
//			count++;
			printf("%d %s \n", count, str);
//			if(count==10) break;
//			printf("%s \n", validStr[count-1]);
		}
	}
	printf("Count of valid strings = %d\n", count);
	for(int i = 0; i<count; i++)
		printf("%s ", validStr[i]);
	return validStr;
}

int chkValid(char* arr)
{
	int flag=0;
	for(int j = 0; j<strlen(arr); j++)
		if(!isalpha(arr[j]))
			flag=1;
	return flag;
}

char** chkValidArray(char** arr, int n)
{
	char** validStr = (char**)malloc(sizeof(char*)*n);
	int count = 0;;
	for(int i = 0; i < n; i++)
	{
		if(chkValid(arr[i])==0)
			validStr[count++] = arr[i];
	}
	printf("No of valid strings = %d\n", count);
	return validStr;
}

char** parseString(char* s)
{
	int n = strlen(s);
}
