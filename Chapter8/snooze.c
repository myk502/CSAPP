#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>
#include"csapp.h"
int total_sleep_time = 0;
int have_slept_time = 0;
void sigint_handler(int signum)
{
	sleep(10);
}

int main(int argc, char** argv)
{
	total_sleep_time = atoi(argv[1]);
	Signal(SIGINT, sigint_handler);
	have_slept_time = sleep(total_sleep_time);
	printf("\nSlept for %d of %d secs.\n", total_sleep_time - have_slept_time, total_sleep_time); 
	return 0;
}
