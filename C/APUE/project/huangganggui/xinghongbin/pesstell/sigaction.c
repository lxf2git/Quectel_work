//#include"/home/apue/apue.h"
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int ch;
void func(int sig,siginfo_t * info,void *p)
{
//		printf("signal:from uid:%d press:%d data:%c\n",info->si_uid,info->si_pid,info->si_value.sival_int);
		printf("%c",info->si_value.sival_int);
		fflush(NULL);
}
void fun(int signo)
{
//		printf("timeover\n");
		union sigval v;
		v.sival_int = ch;
		sigqueue(getppid(),SIGUSR2,v);
		exit(0);

}
int main(int argc,char ** argv)
{
		if(argc < 2)
		{
				printf("user error (a.out filename)\n");
				exit(-1);
		}
		struct sigaction act;
		act.sa_sigaction = func;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR2,&act,NULL);

		int fd;
		FILE *fp;
//		char ch;
		fd = open(argv[1],O_RDWR);
		if(fd == -1)
		{
				perror("open file");
				exit(-1);
		}
		fp = fdopen(fd,"r");
		
	
		
		while( (ch=fgetc(fp)) != -1)
		{
				if(fork()== 0)
				{
//						signal(SIGALRM,fun);
//						alarm(1);
												
					//	printf("uid: %d pid :%d\n",getuid(),getpid());
					//	printf("%c\n",ch);
						while(1);
				}
				else
				{
						pause();
				}
		}
		
}
