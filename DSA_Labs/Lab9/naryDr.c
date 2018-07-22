//#include"iter2.h"
#include"nary.h"

int main()
{
	Tree t = createTree(5);
	printf("%d \n", t->root->val);
	iterator it = getChildren(t);
	for(int i = 0; i < 5; i++)
		printf("%d ", t->root->arr[i]->val);
	printf("\n");
//	printf("%d ", hasMoreElements(it));
	printf("%d ", getNextElement(it)->val);
	printf("%d ", getNextElement(it)->val);
//	while(hasMoreElements(it))
//	{
//		Tnode temp = getNextElement(it);
//		printf("%d ", temp->val);
//	}
	return 0;
}
