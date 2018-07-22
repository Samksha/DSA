#include"nary.h"

void seed()
{
	srand(time(NULL));
}

int getRand()
{
	return rand()%10;
}

struct node* createNode(int v, int n)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->val = v;
	temp->arr = (struct node**)malloc(sizeof(struct node*)*n);
	for(int i = 0; i < n; i++)
		temp->arr[i] = NULL;
	return temp;
}

struct tree* createTree()
{
	struct tree* t = (struct tree*)malloc(sizeof(struct tree));
	t->root = createNode(getRand(), 5);
	t->height = 1;
	struct node* temp = t->root;
	while(t->height>0)
	{
		for(int i = 0; i < 5; i++)
			temp->arr[i] = createNode(getRand(), 5);
		temp=temp->arr[0];
		t->height--;
	}
	return t;	

}

/*
struct tree* createTree()
{
	struct tree* t = (struct tree*)malloc(sizeof(struct tree));
	t->height = 0;
	t->root = _createTree(createNode(getRand(), 5), t->height);
	return t;
}

struct node* _createTree(struct node* n, int h)
{
	if(h == 2) return createNode(getRand(), 5);
	else
		for(int i = 0; i < 5; i++)
		{
			n->arr[i] = createNode(getRand(), 5);
			n->arr[i] = _createTree(n->arr[i], ++h);
		}
}
*/

int isEmptyTree(struct tree* t)
{
	return (t->root==NULL)? 0: 1;
}

void bft(struct tree* t)
{
	struct Queue q = createNewQ();
	addQ(&q, t->root);	
	printf("\nBFT Traversal: ");
	while(!isEmptyQ(&q))
	{
		struct node* temp = getFront(&q);
		printf("%d ", temp->val);
		delQ(&q);
		for(int i = 0; temp->arr[i]!=NULL; i++)
			addQ(&q, temp->arr[i]);
	}
}

void dfs(struct tree* t)
{
	_dfs(t->root);
}

void _dfs(struct node* n)
{
	if(n==NULL) return;
	printf("%d ", n->val);
	iterator* ch = getChildren(n);
	while(hasMoreElements(ch))
//	while(ch->itr!=NULL)
		_dfs(getNextElement(ch));
}

iterator* getChildren(struct node* n)
{
	iterator* it = (iterator*)malloc(sizeof(iterator));
	it->index = 0;
//	int i = 0;
	for(int i = 0; n->arr[i] != NULL; i++)
	{
		it->itr = n->arr;
//		printf("%d ", n->arr[i]->val);
//		printf("%d ", it->itr[i]->val);
	}
	return it;
}
