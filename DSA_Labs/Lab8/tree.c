#include"tree.h"

void seed()
{
	srand(time(NULL));
}

int getRand()
{
	return 150+rand()%20;
}

void setNodeVals(struct BinTree* bt)
{
//	for(int i = 0; i < 10000; i++)
	for(int i = 0; i < 50; i++)
		addNode(bt, getRand());
//		addNode(bt, i);
}

struct Node* createNode(int v)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->val = v;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct BinTree* createTree()
{
	struct BinTree* bt = (struct BinTree*)malloc(sizeof(struct BinTree));
	bt->root = createNode(0);
	bt->size = 0;
//	printf("Node value = %d\n", bt->root->val);
	return bt;
}

void addNode(struct BinTree* bt, int v)
{
	struct Node* rt = bt->root;
	struct Node* node = createNode(v);
	if(bt->size == 0)
	{
		bt->root = node;
		bt->size++;
		return;
	}

	bt->size++;
	while(1)
	{
	if(rt->val < node->val)
		if(rt->right==NULL)
		{
			rt->right = node;
			break;
		}
		else
			rt = rt->right;
	else
		if(rt->left == NULL)
		{
			rt->left = node;
			break;
		}
		else
			rt = rt->left;;
	}
	return;
}

struct Node* findNode(struct BinTree* bt, int key)
{
	return findNode_(bt->root, key);
}

struct Node* findNode_(struct Node* n, int key)
{
	if(n==NULL) return NULL;
	if(n->val == key) return n;
	else if(n->val < key) return findNode_(n->right, key);
	else return findNode_(n->left, key);
}

void inOrderPrint(struct Node* root)
{
	while(root!=NULL)
	{
		inOrderPrint(root->left);
		printf("%d ", root->val);
		root = root->right;
	}
}

struct Node* inOrderSucc(struct BinTree* bt, struct Node* node)
{
	if(node->right!=NULL)
	{
		struct Node* s = node->right;
		while(s->left!=NULL) s = s->left;
		return s;
	}

	struct Node* root = bt->root;
	while(root->left->right!=node || root->left!=node)
	{
		if(root->val < node->val)
			root = root->right;
		else
			root = root->left;
	}
	return root;
}

void deleteNode(struct BinTree* bt, int key)
{
	struct Node* temp = findNode(bt, key);
	if(temp==NULL) return;

	if(temp->right == NULL && temp->left == NULL)
		free(temp);
	else if(temp->right == NULL)
		temp = temp->left;
	else if(temp->left == NULL)
		temp = temp->right;
	else
	{
		struct Node* succ = inOrderSucc(bt, temp);
		int t = succ->val;
		succ->val = temp->val;
		temp->val = t;
		if(succ->left==NULL && succ->right==NULL)
			free(succ);
		else
			succ = succ->right;
	}
}

void rotate(struct BinTree* bt, struct Node* X, struct Node* Y, struct Node* Z)
{
	
}
