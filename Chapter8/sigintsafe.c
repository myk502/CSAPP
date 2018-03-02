#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include"csapp.h"

void sigint_handler(int sig)
{
	Sio_puts("\nCaught SIGNINT!\n");
	_exit(0);
}

int main(void)
{
	if(signal(SIGINT, sigint_handler) == SIG_ERR)
		unix_error("Signal_Error!");
	pause();
	return 0;
}
