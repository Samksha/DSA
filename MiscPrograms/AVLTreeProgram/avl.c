#include"avl.h"

void seed()
{
	srand(time(NULL));
}

int getRand()
{
	return rand()%21 + 150;
}

Tree createTree(int n)
{
	return add(NULL, n);
}

Tree add(Tree t, int val)
{
	Node n = (Node)malloc(sizeof(struct _tree));
	n->key = val;
	n->left = NULL;
	n->right = NULL;
	n->balance = 0;
	return addNode(t, n);
}

Tree addNode(Tree t, Node n)
{
	if(t==NULL) return n;
	else if(t->key == n->key) return t;
	else if(t->key < n->key) t->left = addNode(t->left, n);
	else	t->right = addNode(t->right, n);
	return t;
}

Node find(Tree t, int key)
{
	while(t!=NULL)
	{
		if(t->key == key) break;
		else if(t->key > key) t = t->left;	
		else t = t->right;
	}
	return t;
}

Tree inOrderSuccessor(Tree t, Node n)
{
	if(n->right != NULL)
	{
		n = n->right;
		while(n->left != NULL) n = n->left;
		return n;
	}
	Node succ = NULL;
	while(t!=NULL)
	{
		if(n->key < t->key)
		{
			succ = t;
			t = t->left;
		}
		else if(n->key > t->key)
		{
			t = t->right;
		}
		else
			break;
	}
	return succ;
}

Tree delete(Tree t, int key)
{
	if(t==NULL) return t;
	if(t->key == key)
	{
		if(t->right == NULL)
		{
			Node n = t->left;
			free(t);
			return n;
		}
		else if(t->left == NULL)
		{
			Node n = t->right;
			free(t);
			return n;
		}
		else
		{
			t->key = inOrderSuccessor(t,t)->key;
			t->right = delete(t->right, t->key);
			return t;
		}
	}
	else if(t->key>key)
	{
		t->left = delete(t->left, key);
		return t;
	}
	else
	{
		t->right = delete(t->right, key);
		return t;
	}
}

void inOrderPrint(Tree t)
{
	if(t!=NULL)
	{
		inOrderPrint(t->left);
		printf("%d ", t->key);
//		t = t->right;
		inOrderPrint(t->right);
	}
}

int recursiveHeight(Tree t)
{
	if(t==NULL) return 0;
	int left = recursiveHeight(t->left);
	int right = recursiveHeight(t->right);
	if(left>right)
		return left+1;
	else
		return right+1;
}

/*
struct Node* createNode(int val)
{
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	n->height = 0;
	return n;
}

struct Tree* createTree()
{
	struct Tree* t = (struct Tree*)malloc(sizeof(struct Tree));
	t->root = createNode(-1);
	t->size = 0;
	return t;
}

void addNode(struct Tree* t, int val)
{
	if(t->size==0)
	{
		t->root = createNode(val);
		t->size++;
		return;
	}
	t->root = addNode_(t->root, createNode(val));
	t->size++;
}

struct Node* addNode_(struct Node* t, struct Node* n)
{
	if(t==NULL) return n;
	
	if(t->val < n->val)
	{
		t->right =  addNode_(t->right, n);
	}
	else
	{
		t->left =  addNode_(t->left, n);
	}

	t->height = 1+max(t->left->height, t->right->height);
	int balance = getBalance(t);
	if(balance > 1 && n->val < t->left->val) return rightRotate(t);
	if(balance < -1 && n->val > t->right->val) return leftRotate(t);
	if(balance > 1 && n->val > t->left->val)
	{
		t->left = leftRotate(t->left);
		return rightRotate(t);
	}
	if(balance <-1 && n->val < t->right->val)
	{
		t->right = rightRotate(t->right);
		return leftRotate(t);
	}
	
	return t;
}

struct Node* findNode(struct Tree* t, int key)
{
	return findNode_(t->root, key);
}

struct Node* findNode_(struct Node* t, int key)
{
	if(t == NULL)
		return NULL;

	if(t->val == key)
	{
//		printf("Found = %d", t->val);
		return t;
	}	
	if(t->val < key)
	{
		return findNode_(t->right, key);
	}
	else
	{
		return findNode_(t->left, key);
	}
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

int getBalance(struct Node* t)
{
	if(t==NULL) return 0;
	return t->left->height - t->right->height;
}

struct Node* rightRotate(struct Node* y)
{
	struct Node* x = y->left;
	struct Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(y->left->height, y->right->height)+1;
	x->height = max(x->left->height, x->right->height)+1;
	return x;
}

struct Node* leftRotate(struct Node* x)
{
	struct Node* y = x->right;
	struct Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	y->height = max(y->left->height, y->right->height)+1;
	x->height = max(x->left->height, x->right->height)+1;
	return y;	
}

void setVals(struct Tree* t)
{
//	for(int i = 0; i < 100; i++)
		addNode(t, getRand());
	addNode(t, getRand());
}

void inOrderPrint(struct Tree* t)
{
	inOrderPrint_(t->root);
}

void inOrderPrint_(struct Node* n)
{
	while(n!=NULL)
	{
		inOrderPrint_(n->left);
		printf("%d ", n->val);
		n = n->right;
	}
}
*/
