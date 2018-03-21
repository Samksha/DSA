#include "qsort.h"


int main(int argc, char* argv[])
{
	size = 0;

	char * fileName = argv[1];
	printf("%s\n",fileName);

//	char* fileName = "Input.txt";
	int* studentArray = readData(fileName);

	FILE* fp = fopen(fileName, "r");
	fscanf(fp, "%d\n", &size);
	fclose(fp);

	printArray(studentArray, size);

	quickSortKnownKeyRange(studentArray,size, 10, 20);

	printf("\nSorted output is:\n");

	printArray(studentArray, size);

}
