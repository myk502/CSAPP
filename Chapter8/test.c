#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include"csapp.h"
volatile sig_atomic_t flag = 0;
void sigchld_handler(int signum)
{
	int olderrno = errno;
	flag = 1;
	while(wait(NULL) != -1);
	if(errno != ECHILD)
	{
		unix_error("waitpid interrupted!");
		exit(-1);
	}
	errno = olderrno;
}

int main(void)
{
	sigset_t mask, prev, full_set;
	sigemptyset(&mask);
	sigaddset(&mask, SIGCHLD);
	sigfillset(&full_set);
	Signal(SIGCHLD, sigchld_handler);
	//Sigprocmask(SIG_BLOCK, &mask, &prev);
	pid_t child_pid = Fork();
	if(child_pid == 0)
	{
		printf("Child!\n");
		exit(0);
	}
	else
	{
		while(!flag)
			sigsuspend(&full_set);
		printf("Parent!\n");
		flag = 0;
		exit(0);
	}
}
