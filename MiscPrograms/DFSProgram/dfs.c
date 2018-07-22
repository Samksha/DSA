#include <stdio.h>
#include <stdlib.h>
#include"listIter.h"
#include"dfs.h"
#include"list.h"

void seed()
{
	srand(time(NULL));
}

int getRand()
{
	return rand()%100;
}

/*
tnode createNode(int v, int n)
{
	tnode temp = (tnode)malloc(sizeof(struct _tnode));
	temp->val = v;
	temp->arr = (tnode*)malloc(sizeof(tnode)*n);
	return temp;
}

tnode createTree(tnode a, int h, int ch)
{
//	if(h>1) return a;
//	++h;
	for(int i = 0; i < ch; i++)
	{
		a->arr[i] = createNode(getRand(), 5);
//		a->arr[i] = createTree(a->arr[i], h, ch);
//		for(int j = 0; j < ch; j++)
//			a->arr[i]->arr[j] = createNode(i*3, 5);
	}
	return a;
}
*/

tree _createTree(int n, int height)
{
	if(height >= 3)
		return NULL;
	tree t = (tree)malloc(sizeof(struct _tree));
	t->val = getRand();
	t->children = (iter)malloc(sizeof(struct _iterator));
	iter it = t->children;
	if(n>0)
	{
		it->t = _createTree(n, height+1);
		it->next = NULL;
	}
	for(int i = 1; i < n; i++)
	{
		it->next = (iter)malloc(sizeof(struct _iterator));
		it->next->t = _createTree(n, height+1);
		it->next->next = NULL;
		it = it->next;
	}
	return t;
}

tree createTree(int n)
{
	return _createTree(n, 0);
}

boolean isEmpty(tree t)
{
	if(t == NULL) return true;
	else return false;
}

int getRootVal(tree t)
{
	return t->val;
}

Iterator getChildren(tree t)
{
	Iterator it = (Iterator)malloc(sizeof(iter));
	*it = t->children;
	return it;
}

tree selectNextNode(List l)
{
	return getFront(l);
}

List identifyMoreNodes(tree t)
{
	return makeList(getChildren(t));
}

List addMoreNodes_BF(List l1, List l2)
{
	return append(l1, l2);
}

List addMoreNodes_DF(List l1, List l2)
{
	return append(l2, l1);
}

void bft(tree t)
{
	if(!isEmpty(t))
		printf("%d ", t->val);
	List it = makeList(getChildren(t));
	while(!isEmptyL(it))
	{
		t = selectNextNode(it);
		printf("%d ", t->val);
		it = addMoreNodes_BF(it, identifyMoreNodes(t));
	}
}

void dft(tree t)
{
	if(!isEmpty(t))
		printf("%d ", t->val);
	Iterator ch = getChildren(t);
	while(hasMoreElements(ch))
		dft(getNextElement(ch));
/*
	List it = makeList(getChildren(t));
	while(!isEmptyL(it))
	{
		t = selectNextNode(it);
		printf("%d ", t->val);
		it = addMoreNodes_DF(it, identifyMoreNodes(t));
	}
*/
}

/*
void bft(tnode a)
{
	struct Queue q = createNewQ();
	addQ(&q, a);
	while(!isEmptyQ(&q))
//	int count = 11;
//	while(count-->0)
	{
		tnode b = getFront(&q);
		delQ(&q);
		visit(b);
		for(int i = 0; i<5; i++)
			addQ(&q, b->arr[i]);
//		b = getFront(&q);
//		visit(b);
	}
}
*/
