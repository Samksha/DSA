#include"tree.h"

int main()
{
	struct Node* n = createNewNode(1);
	n->left = createNewNode(2);
	n->right = createNewNode(3);
	n->left->left = createNewNode(4);
	n->left->right = createNewNode(5);
//	printf("%d ", n->data);
	printInOrder(n);
	printf("\n");
	printPreOrder(n);
	printf("\n");
	printPostOrder(n);
	printf("\n");
	return 0;
}
