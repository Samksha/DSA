#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int* arr, int l, int h);
void swap(int* a, int* b);
int partition(int* arr, int l, int h);
int medPartition(int* arr, int l, int h, int k);
void printArr(int* arr, int n);
int* createArr(int n);
void seed();
