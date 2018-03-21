#include"clp.h"

int main()
{
	struct timeval t1, t2;
	double elapsedTime;
	struct Point p[] = {{2,3}, {12,30}, {40,50}, {5,1}, {12,10}, {3,4}};

	gettimeofday(&t1, NULL);
	printf("%f ", bruteForce(p, 6));
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	printf("Total time is %lf\n", elapsedTime);

	gettimeofday(&t1, NULL);
	printf("%f ", closest(p, 6));
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec)/1000.0;
	printf("Total time is %lf\n", elapsedTime);
	
//	printf("%f ", dist(&p[1], &p[2]));
	return 0;
}
