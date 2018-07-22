#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tnode
{
	int val;
 	struct tnode** arr;
};

typedef struct tnode* Tnode;
typedef struct tnode** iterator;

Tnode getNextElement(iterator it);
int hasMoreElements(iterator it);

struct lnode
{
	struct tnode* t;
	struct lnode* next;
};

typedef struct lnode* Lnode;

struct tree
{
	Tnode root;
	int height;
};

typedef struct tree* Tree;

int isEmpty(Lnode ll);
struct tnode* delNode(Lnode ll);
void addNode(Lnode ll, Tnode t);
Lnode createLNode();
Tnode createTNode(int val, int k);
void seed();
int getRand();
Tree createTree(int n);
struct tnode** getChildren(Tree t);
