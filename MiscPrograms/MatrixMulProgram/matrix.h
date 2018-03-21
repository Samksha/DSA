#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

//const int MAX = 100;

void* myalloc(long size);
void myfree(void* temp);
void multiplyMatrix(int row1, int col1, int** A, int row2, int col2, int** B);
void multiplyMatrixRec(int row1, int col1, int** A, int row2, int col2, int** B, int** C);
int** createArr(int row, int col);
void printArr(int** arr, int row, int col);
