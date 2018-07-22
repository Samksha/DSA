#include"nary.h"
#define CHK

typedef struct tnode** iterator;

int hasMoreElements(iterator it)
{
	if(it[0]==NULL) return 0;
	else return 1;
}

struct tnode* getNextElement(iterator it)
{
	struct tnode* temp = it[0];

/*
	int addr = &it[0];
	it+=sizeof(struct tnode*);
	struct tnode* temp2 = it[0];
	printf("In func %d \n", temp2->val);
*/
	return temp;
}
