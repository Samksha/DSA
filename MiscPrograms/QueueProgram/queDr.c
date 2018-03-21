#include"que.h"

int main()
{
	struct Queue q = createNewQ();
	printf("%d ", isEmptyQ(&q));
	delQ(&q);
	int i;
	for(i=0; i<10; i++)
		addQ(&q, i);
	printf("%d ", q.size);
	printf("%ld ", getFront(&q));
	delQ(&q);
	printf("%ld ", getFront(&q));
	return 0;
}
