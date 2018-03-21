#include"que.h"

typedef int Priority;
struct MultiQ
{
	struct Queue* qarr;
	Priority hp;
	int size;
};
struct Task
{
	Element TaskID;
	Priority p;
};
struct MultiQ createMQ(int num);
void addMQ(struct MultiQ* mq, struct Task* t);
struct Task nextMQ(struct MultiQ* mq); 
void delNextMQ(struct MultiQ* mq);
Boolean isEmptyMQ(struct MultiQ* mq);
int sizeMQ(struct MultiQ* mq);
int sizeMQbyPriority(struct MultiQ* mq, Priority p);
struct Queue getQueueFromMQ(struct MultiQ* mq, Priority p);
void loadData(FILE *fp, struct MultiQ* mq);
