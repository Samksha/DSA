#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int h1(char* s, int baseNumber, int tableSize);
int collisionCount(char** s, int n, int baseNumber, int tableSize);
char** parseFile(FILE* fp);
char** parseString(char* s);
int chkValid(char* arr);
char** chkValidArray(char** arr, int n);
