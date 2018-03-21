#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <sys/time.h>

struct Point
{
	int x,y;
};

int compareX(const void* a, const void* b);
int compareY(const void* a, const void* b);
float dist(struct Point* a, struct Point* b);
float bruteForce(struct Point* p, int n);
float min(float x, float y);
float stripClosest(struct Point* p, int size, float d);
float closestUtil(struct Point* p, int n);
float closest(struct Point* p, int n);
