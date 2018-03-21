#include"readfile.h"

int main(int argc, char** argv)
{
	for(int i = 0; i<argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	FILE* fp;
	struct Element** arr = createArr(10);
	fp = fopen("1024.txt", "r");
	read(fp, arr);
//	printf("%s ", arr[0]->name);
//	printArr(arr, 10);
	fclose(fp);
	return 0;
}
