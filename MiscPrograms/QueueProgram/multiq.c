#include"multiq.h"

struct MultiQ createMQ(int num)
{
	struct MultiQ* mq = (struct MultiQ*)malloc(sizeof(struct MultiQ));
	mq->qarr = (struct Queue*)malloc(num*sizeof(struct Queue));
	int i;
	for(i=0; i<num; i++)
		mq->qarr[i]=createNewQ();
	mq->size = num;
	mq->hp = -1;
	return *mq;
}

void addMQ(struct MultiQ* mq, struct Task* t)
{
	if(t->p > mq->hp) mq->hp = t->p;
	addQ(&(mq->qarr[t->p]), t->TaskID);
}


struct Task nextMQ(struct MultiQ* mq)
{
	struct Task* t = (struct Task*)malloc(sizeof(struct Task));
	t->p = mq->hp;
	t->TaskID = getFront(&(mq->qarr[mq->hp]));
	return *t;
}

void delNextMQ(struct MultiQ* mq)
{
	delQ(&(mq->qarr[mq->hp]));
}

Boolean isEmptyMQ(struct MultiQ* mq)
{
	int i;
	for(i=0; i<mq->size; i++)
		if(!isEmptyQ(&(mq->qarr[i])))
			return false;
	return true;
}

int sizeMQ(struct MultiQ* mq)
{
	int i, sum;
	sum=1;
	for(i=0; i<mq->size; i++)
		sum+=lengthQ(&(mq->qarr[i]));
	return sum;
}


int sizeMQbyPriority(struct MultiQ* mq, Priority p)
{
	return lengthQ(&(mq->qarr[p]));
}

struct Queue getQueueFromMQ(struct MultiQ* mq, Priority p)
{
	return mq->qarr[p];
}

void loadData(FILE *fp, struct MultiQ* mq)
{
	struct Task* t = (struct Task*)malloc(sizeof(struct Task));
	while(!feof(fp))
	{
		fscanf(fp, "%ld,%d", &(t->TaskID), &(t->p));
		printf("%ld %d \n", t->TaskID, t->p);
		addMQ(mq, t);
	}
	//printf("%d\n", sizeMQ(mq));
}
