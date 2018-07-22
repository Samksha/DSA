#include"hash.h"

int main()
{
	int baseNumber = 5000003;
	int tableSize = 5000;

	int no = h1("abcdef", baseNumber, tableSize);
	printf("HashVal = %d\n", no);

	char* arr[4] = {"abbcd", "abc", "sdfg", "abc"};
	int n = sizeof(arr)/sizeof(arr[0]);
//	int c = collCount(arr, baseNumber, tableSize);
//	printf("Collision count = %d\n", c);

	FILE* fp;
	fp = fopen("aliceinwonderland.txt", "r");
	char** valStrings = parseFile(fp);
	printStrings(valStrings);
	fclose(fp);

	int c = collCount(valStrings, baseNumber, tableSize);
	printf("Collision count = %d\n", c);

	struct HTable* ht = createHashTable(tableSize);


	return 0;
}
