#include"readfile.h"

struct Element** createArr(int n)
{
	struct Element** temp = (struct Element**)malloc(sizeof(struct Element*)*n);
	for(int i = 0; i < n; i++)
	{
		temp[i] = (struct Element*)malloc(sizeof(struct Element));
		temp[i]->name = (char*)malloc(sizeof(char)*10);
		temp[i]->cgpa = 0;
	}
	return temp;
}

void read(FILE* fp, struct Element** arr)
{
	char str[1024];
	int i=0;
//	while(fgets(str, 100, fp)!=NULL)
	char* token;
	while(i<10)
	if(fgets(str, 100, fp)!=NULL)
	{
		token = strtok(str, ",");
		for(int j = 0; j < 2; j++)
		{
			if(j==0)
			{
				strcpy(arr[i]->name, token);
//				printf("%s\t", token);
				token = strtok(NULL, ",");
			}
			else
				arr[i]->cgpa = atof(token);
				//printf("%d\n", atoi(token));
		}
//		sscanf(token, "%f \n", &arr[i]->cgpa);
		i++;
//		puts(str);
	}	
}

void printArr(struct Element** arr, int n)
{
	printf("\n");
	for(int i = 0; i < n; i++)
		printf("%s %f \n", arr[i]->name, arr[i]->cgpa);
	printf("\n");
}
