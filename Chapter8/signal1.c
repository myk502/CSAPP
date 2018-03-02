/* WARNING: The code is buggy! */
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<errno.h>
#include"csapp.h"
const int MAXBUF = 1024;
void handler1(int sig)
{
	int olderrno = errno;
	
	while(waitpid(-1, NULL, 0) > 0)
		Sio_puts("Handler reaped child\n");
	if(errno != ECHILD)
		Sio_error("waitpid error");
	Sleep(1);
	errno = olderrno;
}

int main(void)
{
	int i, n;
	char buf[MAXBUF];

	if(signal(SIGCHLD, handler1) == SIG_ERR)
		unix_error("signal error");

	for(i = 0; i < 3; i++)
	{
		if(Fork() == 0)//child
		{
			printf("Hello from child %d\n", (int)getpid());
			exit(0);
		}
	}
	if((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0)
		unix_error("read");
	printf("Parent processing input\n");
	while(1);
	exit(0);
}
