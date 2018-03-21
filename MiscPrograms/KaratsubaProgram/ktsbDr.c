#include"ktsb.h"

int main()
{
	//struct Queue q = createNewQ();
	
	struct TNode* root = createNewT(1);
	root->left = createNewT(2);
	root->right = createNewT(3);
	root->left->left = createNewT(4);
	root->left->right = createNewT(5);
	printLevelOrder(root);
/*
	printf("%ld ", root->right->data);
	struct Queue q = createNewQ();
	addQ(&q, root);
	addQ(&q, root->right);
	traverseQ(&q);
*/
	return 0;
}
