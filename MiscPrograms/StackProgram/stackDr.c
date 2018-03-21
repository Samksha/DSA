#include"stack.h"

int main()
{
	struct Stack s = createNewS();
	push(&s, 1);
	push(&s, 2);
	printf("%ld ", s.top->data);
	pop(&s);
	printf("%ld ", s.top->data);

	return 0;
}
