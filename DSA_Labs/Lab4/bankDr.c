#include"bank.h"

int main()
{
//	struct Record* r = newRec();
//	struct Record* r2 = newRec();

	struct Record* arr = (struct Record*)malloc(10*sizeof(struct Record));
	int i;
	for(i=0; i< 10; i++)
		arr[i] = newRec();
	FILE *fp;
	fp = fopen("10", "r");
//	fscanf(fp, "\"%lf,%[^,],%[^,],%[^,],%[^\"]\"\n", &r->cardNo, r->code, r->expDate, r->fName, r->lName);
	read(fp, arr);
//	read(fp, r2);
	for(i=0; i<10; i++)
		printRec(&arr[i]);
//	printRec(r2);
//	printf("%lf\n", r->cardNo);
//	printf("%s\n", r->code);
//	printf("%s\n", r->expDate);
	insertionSort(arr, 10);
	fclose(fp);

	return 0;
}
