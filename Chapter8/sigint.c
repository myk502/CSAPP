#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include"csapp.h"

void sigint_handler(int sig)
{
	printf("Caught SIGINT!\n");
	exit(0);
}

int main(void)
{
	Signal(SIGINT, sigint_handler);
	pause();
	return 0;
}
