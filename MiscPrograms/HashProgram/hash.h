#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int h1(char* s, int baseNumber, int tableSize);
int collCount(char** s, int baseNumber, int tableSize);
int chkValid(char* s);
char** parseFile(FILE* fp);
void printStrings(char** arr);

