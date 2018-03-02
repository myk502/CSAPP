#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include"csapp.h"
static size_t sio_strlen(char s[]);
static void sio_ltoa(long v, char s[], int b);
static void sio_reverse(char s[]);
static size_t sio_strlen(char s[])
{
	int i = 0;
	 while(s[i] != '\0')
		 ++i;
	 return i;
}

void unix_error(char* msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

pid_t Fork(void)
{
	pid_t pid;
	if((pid = fork()) < 0)
		unix_error("Fork error");
	return pid;
}

char* Fgets(char* buf, int bufsize, FILE* stream)
{
	if(buf == NULL)
		unix_error("Buffer error");
	if(bufsize <= 0)
		unix_error("Buffer Size Error");
	char* ret_buf = fgets(buf, bufsize, stream);
	if(ferror(stream))
		unix_error("fgets error");
	return ret_buf;
}

void Pause(void)
{
	(void)pause();
	return;
}


static void sio_ltoa(long v, char s[], int b)
{
	int c, i = 0;
	int neg = (v < 0);
	if(neg) 
		v = -v;
	do
	{
		s[i++] = ((c = (v % b)) < 10) ? c + '0' : c - 10 + 'a';
	}
	while((v /= b) > 0);
	if(neg)
		s[i++] = '-';
	s[i] = '\0';
	sio_reverse(s);
}

static void sio_reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

ssize_t sio_puts(char s[])
{
	return write(STDOUT_FILENO, s, sio_strlen(s));
}

ssize_t sio_putl(long v)
{
	char s[128];
	sio_ltoa(v, s, 10);
	return sio_puts(s);
}

void sio_error(char s[])
{
	sio_puts(s);
	_exit(1);
}

ssize_t Sio_putl(long v)
{
	ssize_t n;
	if((n = sio_putl(v) < 0))
			sio_error("Sio_putl error");
	return n;
}

ssize_t Sio_puts(char s[])
{
	ssize_t n;
	if((n = sio_puts(s)) < 0)
		sio_error("Sio_puts error");
	return n;
}

void Sio_error(char s[])
{
	sio_error(s);
}

unsigned int Sleep(unsigned int secs)
{
	unsigned int rc;
	if((rc = sleep(secs)) < 0)
		unix_error("Sleep error");
	return rc;
}
handler_t* Signal(int signum, handler_t* handler)
{
	struct sigaction action, old_action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	if(sigaction(signum, &action, &old_action) < 0)
		unix_error("Signal error");
	return (old_action.sa_handler);
}

void Sigprocmask(int how, const sigset_t* set, sigset_t* oldset)
{
	if(sigprocmask(how, set, oldset) < 0)
		unix_error("Sigprocmask error");
	return;
}

void Execve(const char* filename, char* const argv[], char* const envp[])
{
	if(execve(filename, argv, envp) < 0)
		unix_error("Execve error");
}

void Sigfillset(sigset_t* set)
{
	if(sigfillset(set) < 0)
		unix_error("Sigfillset error");
	return;
}

void Sigemptyset(sigset_t* set)
{
	if(sigemptyset(set) < 0)
		unix_error("Sigemptyset error");
	return ;
}

void Sigaddset(sigset_t* set, int signum)
{
	if(sigaddset(set, signum) < 0)
		unix_error("Sigaddset error");
	return;
}

pid_t Waitpid(pid_t pid, int* iptr, int options)
{
	pid_t retpid;
	if((retpid = waitpid(pid, iptr, options)) < 0)
		unix_error("Waitpid error");
	return retpid;
}
