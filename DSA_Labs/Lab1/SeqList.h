#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int key;
}Key;
typedef struct 
{
	int e;
}Element;
struct Node 
{
	//Element e;
	int e;
	struct Node* next;
};
typedef struct 
{
	struct Node* head;
	struct Node* tail;
}SeqList;
SeqList newList();
SeqList insertInOrder(SeqList sl, Element e);
SeqList insertAtFront(SeqList sl, Element e);
SeqList insertAtEnd(SeqList sl, Element e);
SeqList delete(SeqList sl, Element e);
SeqList deleteAtFront(SeqList sl);
Element find(SeqList sl, Key k);
SeqList merge(SeqList sl1, SeqList sl2);
SeqList insertionSort(SeqList sl, Key k);
