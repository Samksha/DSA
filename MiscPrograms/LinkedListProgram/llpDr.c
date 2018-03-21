#include"llp.h"

extern long heap_mem;

int main()
{
	struct LList list = createList(10);
	printList(&list);
	printf("%ld \n", heap_mem);
	createCycle(&list, 10);
	printf("%d ", testCyclic(&list));
	makeCircularList(&list);
	return 0;
}
