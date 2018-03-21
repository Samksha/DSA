#include "List.h"

void* myalloc(int size)
{
	char* buffer = (char*)malloc(sizeof(int)+size);
	if(buffer == NULL) return NULL;
	globalCounter += size;
	int* sizeBox = (int*) buffer;
	*sizeBox = size;
	return buffer+sizeof(int);
}

void myfree(void* ptr)
{
	if(ptr == NULL) return;
	char* buffer = (char*)ptr - sizeof(int);
	int *sizeBox = (int*) buffer;
	globalCounter -= *sizeBox;
	free(buffer);
}

void addNode(List l, Student s)
{
	Node temp = (Node)myalloc(sizeof(struct node));
	temp->next = NULL;
	temp->record = s;
	if(l->count == 0)
	{
		l->first = temp;
		l->last = temp;
		l->count++;
		return;
	}
	l->last->next = temp;
	l->last = temp;
	l->count++;
}

List createList(Student studArray, int arraySize)
{
	List l = (List)myalloc(sizeof(struct list));
	l->count = 0;
	l->first = NULL;
	l->last = NULL;
	for(int i=0; i<arraySize; i++)
		addNode(l, &studArray[i]);
	return l;
}

void insertInOrder(List list, Node newNode)
{
	Node current = (Node)myalloc(sizeof(struct node));
	if(list->first == NULL || list->first->record->marks >= newNode->record->marks)
	{
		newNode->next = list->first;
		list->first = newNode;
		myfree(current);
	}
	else
	{
		current = list->first;
		while(current->next != NULL && current->next->record->marks < newNode->record->marks)
			current = current->next;
		newNode->next = current->next;
		current->next = newNode;
	}
}

List insertionSort(List list)
{
	List sorted = (List)myalloc(sizeof(struct list));
	sorted->first = NULL;
	sorted->last = NULL;
	Node current = list->first;
	while(current!=NULL)
	{
		Node nxt = current->next;
		insertInOrder(sorted, current);
		current = nxt;
	}
	sorted->count = list->count;
	return sorted;
}

double measureSortingTime(List list)
{
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1, NULL);
	insertionSort(list);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	return elapsedTime;
}
