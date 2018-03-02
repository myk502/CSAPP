#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
	char* str = getenv("PWD");
	printf("%s\n", str);
	return 0;
}
