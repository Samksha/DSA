#include <stdio.h>
#include"dfs.h"

int main()
{
	int ch = 5;
	int h = 0;
	tree a = createTree(3);
	bft(a);
	printf("\n");
	dft(a);
/*
	printf("Level1: %d ", a->val);
	a = createTree(a, h, ch);
	printf("\nLevel2: ");
	for(int i = 0; i < ch; i++)
		printf("%d ", a->children[i]->val);

	printf("\nLevel3: ");	
	for(int i = 0; i < ch; i++)
	{
		for(int j = 0; j < ch; j++)
			printf("%d ", a->arr[i]->arr[j]->val);
		printf("\n\t");
	}
	printf("\n");
*/
//	bft(a);
	return 0;
}
