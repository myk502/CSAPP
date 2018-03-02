#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include"csapp.h"
#define N 5
int main(void)
{
	int status, pid[N], i = 0, retpid;
	for(int i = 0; i < N; i++)
	{
		pid[i] = Fork();
		if(pid[i] == 0)// child process
			exit(100 + i);// exit without condition
	}
	int tempval;
	if((tempval = Fork()) == 0)
		exit(0);
	while((retpid = waitpid(pid[i++], &status, 0)) > 0)
	{
		if(WIFEXITED(status))//if exit normally
			printf("Child %d terminated normally with exit status=%d\n", i, WEXITSTATUS(status));
		else
			printf("Child %d terminated abnormally\n", i);
	}
	if(errno != ECHILD)
		unix_error("waitpid error");
	return 0;
}
