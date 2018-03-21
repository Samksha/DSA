#include"hash.h"

int main()
{
	//int h = h1("abcd", 36, 100);
	//printf("Hash = %d", h);

	//char* arr[3] = {"abcd", "abc", "abcd"};
	//int count = collisionCount(arr, sizeof(arr)/sizeof(arr[0]), 36, 100);
	//printf("Collision count = %d\n", count);

	//char* arr2[4] = {"Project", "Gutenberg's", "Alice's", "Adventures"};
	//char** a = chkValidArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

	
//	FILE* fp = fopen("stopwords.txt", "r");
	FILE* fp = fopen("aliceinwonderland.txt", "r");
	char** arr3 = parseFile(fp);
	fclose(fp);

	int count = collisionCount(arr3, 22698, 36, 100);
	printf("Collision count = %d\n", count);
	
	return 0;
}
