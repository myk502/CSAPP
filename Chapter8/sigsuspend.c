#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>
#include"csapp.h"

volatile sig_atomic_t pid;

void sigchld_handler(int s)
{
	int olderrno = errno;
	pid = Waitpid(-1, NULL, 0);
	errno = olderrno;
}

void sigint_handler(int s)
{

}

int main(int argc, char** argv)
{
	sigset_t mask, prev;
	Signal(SIGCHLD, sigchld_handler);
	Signal(SIGINT, sigint_handler);
	Sigemptyset(&mask);
	Sigaddset(&mask, SIGCHLD);
	while(1)
	{
		Sigprocmask(SIG_BLOCK, &mask, &prev);
		if(Fork() == 0)
			exit(0);

		pid = 0;
		while(!pid)
			sigsuspend(&prev);
		Sigprocmask(SIG_SETMASK, &prev, NULL);
		printf(".");
	}
	return 0;
}
