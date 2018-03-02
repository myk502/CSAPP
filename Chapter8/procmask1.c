/* Warning, The code is buggy! */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include"csapp.h"

void handler(int sig)
{
	int olderrno = errno;
	sigset_t mask_all, prev_all;
	pid_t pid;
	Sigfillset(&mask_all);
	while((pid = waitpid(-1, NULL, 0)) > 0)
	{
		Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
		deletejob(pid);
		Sigprocmask(SIG_SETMASK, &prev_all, NULL);
	}
	if(errno != ECHILD)
		Sio_error("waitpid error");
	errno = olderrno;
}

int main(int argc, char** argv)
{
	int pid;
	sigset_t mask_all, prev_all;

	Sigfillset(&mask_all);
	Signal(SIGCHLD, handler);
	initjobs();
	while(1)
	{
		if((pid = Fork()) == 0)
			Execve("/bin/date", argv, NULL);
		Sigprocmask(SIG_BLOCK, &mask_all, &prev_all);
		addjob(pid);
		Sigprocmask(SIG_SETMASK, &prev_all, NULL);
	}
	return 0;
}
