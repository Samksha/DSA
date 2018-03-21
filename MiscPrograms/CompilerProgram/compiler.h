#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};
struct Stack* createStack(unsigned capacity);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char c);
char peek(struct Stack* stack);
char pop(struct Stack* stack);
int isOperand(char ch);
int precOrder(char ch);
int convertToPost(char* exp);
void convertToMachine(char* exp);
