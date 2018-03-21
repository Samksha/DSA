#include"clp.h"

int compareX(const void* a, const void* b)
{
	struct Point* p1 = (struct Point*) a;
	struct Point* p2 = (struct Point*) b;
	return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
	struct Point* p1 = (struct Point*) a;
	struct Point* p2 = (struct Point*) b;
	return (p1->y - p2->y);
}

float dist(struct Point* p1, struct Point* p2)
{
	return sqrt( (p1->x - p2->x)*(p1->x - p2->x) + (p1->y - p2->y)*(p1->y - p2->y));
}

float bruteForce(struct Point* p, int n)
{
	float min = FLT_MAX;
	int i,j;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(dist(&p[i], &p[j]) < min)
				min = dist(&p[i], &p[j]);
	return min;
}	

float min(float x, float y)
{
	return (x<y)?x:y;
}

float stripClosest(struct Point* strip, int size, float d)
{
	float min = d;
	qsort(strip, size, sizeof(struct Point), compareY);
	int i,j;
	for(i=0; i<size; i++)
		for(j=i+1; j<size && (strip[j].y - strip[i].y)<min; j++)
			if(dist(&strip[i], &strip[j]) < min)
				min = dist(&strip[i], &strip[j]);
	return min;
}

float closestUtil(struct Point* p, int n)
{
	if(n<=3)
		return bruteForce(p,n);
	
	//Finding middle point
	int mid=n/2;
	struct Point midPoint = p[mid];
	
	//Calculate recursively
	float dl = closestUtil(p, mid);
	float dr = closestUtil(p+mid, n-mid);

	float d = min(dl,dr);

	struct Point strip[n];
	int j = 0;
	for(int i=0; i<n; i++)
		if(abs(p[i].x - midPoint.x) < d)
			strip[j++]=p[i];
	return min(d, stripClosest(strip, j, d));
}

float closest(struct Point* p, int n)
{
	qsort(p, n, sizeof(struct Point), compareX);
	return closestUtil(p, n);
}
