#include"compiler.h"

int convertToPost(char* exp)
{
	int i,k;
	struct Stack* stack = createStack(strlen(exp));
	if(!stack)
		return -1;
	for(i=0,k=-1;exp[i];++i)
	{
		if(isOperand(exp[i]))
			exp[++k]=exp[i];
		else if(exp[i]=='(')
			push(stack, exp[i]);
		else if(exp[i]==')')
		{
			while(!isEmpty(stack) && peek(stack)!='(')
				exp[++k]=pop(stack);
			if(isEmpty(stack))
				return -1;
			else
				pop(stack);
		}
		else
		{
			while(!isEmpty(stack) && precOrder(exp[i])<=precOrder(peek(stack)))
				exp[++k]=pop(stack);
			push(stack, exp[i]);			
		}
	}
	while(!isEmpty(stack))
		exp[++k]=pop(stack);
	exp[++k]='\0';
	return 0;
	//printf("%s\n", exp);		
}

void convertToMachine(char* exp)
{
	int i,j,k;
	j=1;
	struct Stack* stack = createStack(strlen(exp));
	if(!stack)
		return;
	for(i=0,k=-1; exp[i]; ++i)
	{
		if(isOperand(exp[i]))
			push(stack, exp[i]);
		else
		{
			char c1 = pop(stack);
			char c2 = pop(stack);
			if(c2=='@')
				printf("LD TEMP%d\n", j);
			else
				printf("LD %c\n", c2);
			if(exp[i]=='*')
			{
				printf("MUL %c\n", c1);
				push(stack, j);
				printf("ST TEMP%d\n", j++);
			}
			else if(exp[i]=='+')
			{
				printf("ADD %c\n", c1);
				push(stack, j); 
				printf("ST TEMP%d\n", j++);
			}
			else if(exp[i]=='-')
			{
				printf("SUB %c\n", c1);
				push(stack, j);
				printf("ST TEMP%d\n", j++);
			}
			else
			{
				printf("DV %c\n", c1);
				push(stack, j);
				printf("ST TEMP%d\n", j++);
			}
		}
	}		
}
