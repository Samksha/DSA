#include"multiq.h"
#include <sys/time.h>

int main()
{
	struct timeval t1, t2;
	double elapsedTime;
	struct MultiQ mq = createMQ(10);
	FILE *fp;
	struct Task* t = (struct Task*)malloc(sizeof(struct Task));
	fp = fopen("input10.txt", "r");
	gettimeofday(&t1, NULL);
	loadData(fp, &mq);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	printf("Total time is %f ms.\n", elapsedTime);
	fclose(fp);

	/*
	struct Task* t = (struct Task*)malloc(sizeof(struct Task));
	t->p = 1;
	t->TaskID = 10000;
	addMQ(&mq, t);
	int i;
	for(i=0; i<10; i++)
	{
		t->p = i;
		t->TaskID = 10000+i;
		addMQ(&mq, t);
	}
	printf("%d ", sizeMQbyPriority(&mq, 1));
	printf("%ld ", t->TaskID);
	delNextMQ(&mq);
	struct Task temp = nextMQ(&mq);
	printf("%ld ", temp.TaskID);
	*/

	return 0;
}
