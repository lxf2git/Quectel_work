#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc ,char**argv)
{
		int pid;
		int sig;
		sig = atoi(argv[1]+1);
	
		pid = atoi(argv[2]);
		printf("pid:%dsig:%d\n",pid,sig);
		kill(pid,sig);
}
