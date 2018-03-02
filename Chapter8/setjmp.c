#include<setjmp.h>
#include<stdio.h>
#include<stdlib.h>
#include"csapp.h"

jmp_buf buf;
int error1 = 0, error2 = 1;
void foo(void);
static int x;
void bar(void);
int main(void)
{
	switch(setjmp(buf))
	{
		case 0:
			foo();
			break;
		case 1:
			printf("Detected an error1 conditon in foo\n");
			break;
		case 2:
			printf("Detected an error2 conditon in foo\n");
			break;
		default:
			printf("Unknown error condition in foo\n");
	}
	exit(0);
}

void foo(void)
{
	if(error1)
		longjmp(buf, 1);
	bar();
}

void bar(void)
{
	if(error2)
		longjmp(buf, 2);
}
