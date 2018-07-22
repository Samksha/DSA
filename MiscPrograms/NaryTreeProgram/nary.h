#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include"stack.h"
#include"iter.h"

/*
struct node
{
	int val;
	struct node** arr;	
};
*/

struct tree
{
	struct node* root;
	int height;
};

void seed();
int getRand();
struct node* createNode(int v, int n);
struct tree* createTree();
struct node* _createTree(struct node* n, int h);
int isEmptyTree(struct tree* t);
void bft(struct tree* t);
//dft_(struct node* n);
void dfs(struct tree* t);
void _dfs(struct node* n);
iterator* getChildren(struct node* n);
