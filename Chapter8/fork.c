#include<sys/types.h>
#include"csapp.h"
#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	pid_t pid;
	int x = 1;

	pid = Fork();
	if(pid == 0)//child process
	{
		printf("child : x=%d\n", ++x);
		exit(0);
	}
	printf("parent: x=%d\n", --x);
	exit(0);
}

