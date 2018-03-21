#include <stdio.h>
#include <stdlib.h>

typedef long Element;  
struct Node
{
	Element ele; 
 	struct Node* next;
};

//typedef enum  { false, true } Boolean; 
struct Queue
{
	struct Node* front;
	struct Node* rear;
	int size;
};

struct Queue newQ();
int isEmptyQ(struct Queue q);
Element front(struct Queue q);
struct Queue addQ(struct Queue q, Element e);
struct Queue delQ(struct Queue q);
int lengthQ(struct Queue q); 
void traverse(struct Queue q);
