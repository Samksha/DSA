#include"compiler.h"

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	if(!stack) return NULL;
	stack->top=-1;
	stack->capacity=capacity;
	stack->array=(int*)malloc(stack->capacity*sizeof(int));
	if(!stack->array) return NULL;
	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top==-1;
}

void push(struct Stack* stack, char* ch)
{
	stack->array[++stack->top]=ch;	
}

char* peek(struct Stack* stack)
{
	return stack->array[stack->top];	
}

char* pop(struct Stack* stack)
{
	if(!isEmpty(stack))
		return stack->array[stack->top--];
	return "$";
}

int isOperand(char ch)
{
	return (ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z');	
}

int precOrder(char ch)
{
	switch(ch)
	{
		case '+': 
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
