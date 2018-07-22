#include"bst.h"

tree createNode(int key)
{
	tree t = (tree)malloc(sizeof(struct _tree));
	t->left = t->right = NULL;
	t->key = key;
	return t;
}

void inOrder(tree t)
{
	if(t!=NULL)
	{
		inOrder(t->left);
		printf("%d ", t->key);
		inOrder(t->right);
	}
}

tree add(tree t, int key)
{
	tree n = createNode(key);
	return addNode(t, n);
}

tree addNode(tree t, tree n)
{
	if(t==NULL) return n;
	if(t->key > n->key) t->left = addNode(t->left, n);
	else t->right = addNode(t->right, n);
	return t;
}

tree insert(tree t, int key)
{
	if(t==NULL) return createNode(key);
	if(t->key > key) t->left = insert(t->left, key);
	else t->right = insert(t->right, key);
	return t;
}

tree minValNode(tree t)
{
	tree cur = t;
	while(cur->left != NULL)
		cur = cur->left;
	return cur;
}

tree delete(tree t, int key)
{
	if(t==NULL) return NULL;
	
	if(t->key > key) t->left = delete(t->left, key);

	else if(t->key < key) t->right = delete(t->right, key); 

	else
	{
	if(t->right == NULL)
	{
		tree a = t->left;
		free(t);
		return a;
	}
	else if(t->left == NULL)
	{
		tree b = t->right;
		free(t);
		return b;
	}
	
	tree temp = minValNode(t->right);
	t->key = temp->key;
	t->right = delete(t->right, temp->key);
	}
	return t;
}
