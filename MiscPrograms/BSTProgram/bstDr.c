#include"bst.h"

int main()
{
	tree t = NULL;
	t = add(t, 50);
	t = add(t, 30);
	t = add(t, 20);
	t = add(t, 40);
	t = add(t, 70);
	t = add(t, 60);
	t = add(t, 80);
	inOrder(t);
	printf("\n");
	
	t = delete(t, 30);
	t = delete(t, 60);
	inOrder(t);

	return 0;
}
