#include"llp.h"

extern long heap_mem;

int main()
{
//	allocateArr();
	struct LList list = createList(10);
	printf("%ld \n", heap_mem);
	printList(&list);
	createCycle(&list, 10);
	printf("Test Cycle: ");
	int b = testCyclic(&list);
	printf("%d \n", b);

/*
	long num = 1000;
	while(1)
	{
		int* arr = (int*)malloc(num*sizeof(int));
		num*=num;
		if(arr==NULL) break;
	}

	printf("%ld \n", heap_mem);
*/

	return 0;
}
