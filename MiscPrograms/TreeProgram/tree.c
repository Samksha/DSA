#include"tree.h"

struct Node* createNewNode(int d)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->data=d;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void printInOrder(struct Node* n)
{
	if(n==NULL) return;
	printInOrder(n->left);
	printf("%d ", n->data);
	printInOrder(n->right);
}

void printPreOrder(struct Node* n)
{
	if(n==NULL) return;
	printf("%d ", n->data);
	printPreOrder(n->left);
	printPreOrder(n->right);
}

void printPostOrder(struct Node* n)
{
	if(n==NULL) return;
	printPostOrder(n->left);
	printPostOrder(n->right);
	printf("%d ", n->data);
}

void bfsTraversal(struct Node* n)
{
	return;

}
