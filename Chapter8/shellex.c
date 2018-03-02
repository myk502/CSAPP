#include<sys/types.h>
#include<stdio.h>
#define __USE_GNU
//For the use of environ
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h>
#include"csapp.h"
#define MAXARGS 128
#define MAXLINE 1024
/*Function prototypes */
void eval(char* cmdline);
int parseline(char* buf, char** argv);
int builtin_command(char** argv);

int main(void)
{
	char cmdline[MAXLINE];
	while(1)
	{
		printf("> ");
		Fgets(cmdline, MAXLINE, stdin);
		if(feof(stdin))
			exit(0);

		eval(cmdline);
		
	}
	return 0;
}

void eval(char* cmdline)
{
	char* argv[MAXARGS];
	char buf[MAXLINE];
	int bg;//whether background
	pid_t pid;

	strcpy(buf, cmdline);
	bg = parseline(buf, argv);
	if(argv[0] == NULL)
		return;//This is an empty line

	if(!builtin_command(argv))
	{
		if((pid = Fork()) == 0)// is child process
		{
			if(execve(argv[0], argv, environ) < 0)
			{
				printf("%s: Command not found.\n", argv[0]);
				exit(0);
			}
		}

		if(!bg)//foreground, need to wait for child process dying
		{
			int status;
			if(waitpid(pid, &status, 0) < 0)
				unix_error("waitfg: waitpid error");
		}
		else
			printf("%d %s", pid, cmdline);
	}
	return;
}

/* If first arg is a builtin command, run it and return true */

int builtin_command(char** argv)
{
	if(!strcmp(argv[0], "quit"))//quit command
		exit(0);
	if(!strcmp(argv[0], "&"))
		return 1;
	return 0;
}

/* parseline- Pase the command line and build the argv array */

int parseline(char* buf, char** argv)
{
	char* delim;//a pointer to first space delimiter
	int argc;
	int bg;

	buf[strlen(buf) - 1] = ' '; //replace '\n' with space
	while(*buf && (*buf == ' '))//ignore leading space, the first argument is to avoid pointer overlap
		buf++;
	
	/* Build the argv list */
	argc = 0;
	while((delim = strchr(buf, ' ')))//if not found, return NULL, end the loop
	{
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while(*buf && (*buf == ' '))
			buf++;
	}
	argv[argc] = NULL;
	if(argc == 0)//This is a blank line
		return 1;
	//decide whether background
	if((bg = (*argv[argc - 1] == '&')) != 0)
		argv[--argc] = NULL;

	return bg;

}
