#include"multiq.h"

MultiQ createMQ(int num)
{
	MultiQ mq = (struct Queue*)malloc(num*sizeof(struct Queue));
	return mq; 
}

void addMQ(MultiQ* mq, struct Task t)
{
	addQ(*mq[t.p], t.TaskID);
}
