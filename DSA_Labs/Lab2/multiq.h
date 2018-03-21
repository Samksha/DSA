#include"que.h"

typedef struct Queue* MultiQ;
typedef int Priority;
struct Task
{
	Element TaskID;
	Priority p;
};

MultiQ createMQ(int num);
void addMQ(MultiQ* mq, struct Task t);
struct Task nextMQ(MultiQ* mq);
void delNextMQ(MultiQ* mq);
int isEmptyMQ(MultiQ* mq);
int sizeMQ(MultiQ* mq);
int sizeMQbyPriority(MultiQ* mq, Priority p);
struct Queue getQueueFromMQ(MultiQ* mq, Priority p);
