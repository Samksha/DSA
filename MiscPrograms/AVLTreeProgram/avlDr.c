#include"avl.h"

int main()
{
 	Tree t = createTree(50);
	t = add(t, 30);
	t = add(t, 20);
	t = add(t, 40);
	t = add(t, 70);
	t = add(t, 60);
	t = add(t, 80);

//	printf("%d ", t->key);

//	for(int i = 0; i < 10; i++)
//		t = add(t, getRand());

	inOrderPrint(t);

	t = delete(t, 60);	
	inOrderPrint(t);
	return 0;
}

/*
int main()
{
	struct Tree* t = createTree();
//	addNode(t, 10);
	setVals(t);
	inOrderPrint(t);
	
//	int key = getRand();
//	struct Node* n = findNode(t, key);
//	printf("\n Key = %d", key);
//	if(n==NULL) printf("asdfg");
//	else printf("%d", n->val);
//	if(n!=NULL)
//		printf("\n Key = %d, Found = %d\n", key, n->val);
	return 0;
}
*/
