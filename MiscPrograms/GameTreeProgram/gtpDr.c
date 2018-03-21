#include"gtp.h"

int main()
{
	struct Queue q = createNewQ();
	int i;
	for(i=0; i < 10; i++)
		addQ(&q, i);
	traverse(&q);
	for(i=1; i < 6; i++)
		delQ(&q);
	traverse(&q);
	return 0;
}
