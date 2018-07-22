//#include"iter.h"
#include"nary.h"

void seed()
{
	srand(time(NULL));
}

int getRand()
{
	return rand()%10;
}

int isEmpty(Lnode ll)
{
	if(ll->t==NULL) return 0;
	else return 1;
}

Tnode delNode(Lnode ll)
{
	if(isEmpty(ll)) return NULL;

	Tnode temp = createTNode(ll->t->val, 0);
	ll = ll->next;
	return temp;
}

Tnode createTNode(int val, int k)
{
	Tnode temp = (Tnode)malloc(sizeof(struct tnode));
	temp->val = val;
	temp->arr = (Tnode*)malloc(sizeof(Tnode)*k);
	for(int i = 0; i < k; i++)
		temp->arr[i] = NULL;
	return temp;
}

Lnode createLNode()
{
	Lnode temp = (Lnode)malloc(sizeof(struct lnode));
	temp->t = NULL;
	temp->next = NULL;
	return temp;
}

Tree createTree(int n)
{
 	Tree t = (Tree)malloc(sizeof(struct tree));
	t->root = createTNode(getRand(), n);
	for(int i = 0; i < n; i++)
	{
		t->root->arr[i] = createTNode(getRand(), n);
		printf("%d ", t->root->arr[i]->val);
	}
	return t;
}

int isEmptyTree(Tree t)
{
	if(t->root == NULL) return 0;
	else return 1;
}

int getRootVal(Tree t)
{
	return t->root->val;
}

iterator getChildren(Tree t)
{
	return t->root->arr;
}
