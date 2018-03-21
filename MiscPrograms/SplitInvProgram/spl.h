#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createArr(int num);
void printArr(int* arr, int size);
void getRand(int* arr, int size);
int mergeSort(int* arr, int l, int r);
int merge(int* arr, int l, int m, int r);
