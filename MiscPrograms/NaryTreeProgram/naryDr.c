#include"nary.h"

int main()
{
	struct tree* t = createTree();

/*	printf("Level1: %d ", t->root->val);
	printf("\nLevel2: ");
	for(int i = 0; i < 5; i++)
		printf("%d ", t->root->arr[i]->val);
	printf("\n");
*/
/*
	iterator* it = getChildren(t->root);

	while(hasMoreElements(it))
//	while(it->itr[it->index]!=NULL)
	{
		struct node* temp = getNextElement(it);
		printf("%d ", temp->val);
	}
*/
//	dfs(t);
	bft(t);

	return 0;
}
