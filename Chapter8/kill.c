#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include"csapp.h"

int main(void)
{
	pid_t pid;
	if((pid = Fork()) == 0)
	{
		Pause();
		printf("control should never reach here!\n");
		exit(0);
	}

	kill(pid, SIGKILL);
	exit(0);
	return 0;
}
