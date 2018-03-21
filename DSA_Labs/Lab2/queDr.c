#include"que.h"

int main()
{
	struct Queue q = newQ();
	//printf("%d", isEmptyQ(q));
	q = addQ(q, 1);
	q = addQ(q, 2);
	traverse(q);
//	printf("%d", front(q));
	return 0;
}
