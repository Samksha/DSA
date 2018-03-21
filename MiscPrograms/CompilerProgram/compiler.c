#include"compiler.h"

int main()
{
	char input[] = "(a+b*c)/(d-e)";
	//char input[] = "a+b*(c^d-e)^(f+g*h)-i";
	convertToPost(input);
	printf("%s\n", input);
	convertToMachine(input);
	return 0;
}
