#include"tree.h"

int main()
{
	seed();
//	printf("%d ", getRand());

	struct BinTree* bt = createTree();
	setNodeVals(bt);
	printf("%d ", bt->size);
//	inOrderPrint(bt->root);


	struct Node* f = findNode(bt, getRand());
//	int f = findNode(bt, 9795);
	printf("%d \n", f->val);

	inOrderPrint(bt->root);
	printf("\n");

	deleteNode(bt, f->val);

	inOrderPrint(bt->root);
	printf("\n");

	return 0;
}
