#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>

int main(void)
{
	fork();
	pid_t pid = getpgrp();
	printf("pgid:%d\n", pid);
	printf("pid:%d\n", getpid());
	return 0;
}
