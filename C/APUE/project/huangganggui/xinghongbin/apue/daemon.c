#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
void sig_fun(int sig);
int output_note();
int main()
{
		int fd;
		fd = open("/dev/null",O_RDWR);
		if(fd == -1)
		{
				perror("null");
				return -1;
		}
		if(fork() == 0)
		{
				printf("%d\n",getpid());
				signal(SIGHUP,sig_fun);
				signal(SIGUSR1,sig_fun);
				chdir("/");
				dup2(fd,0);
				dup2(fd,1);
				dup2(fd,2);
				setsid();
				while(1)
					;
		}
		return 0;
}
void sig_fun(int sig)
{

		if(sig == SIGHUP)
		{
				output_note();
				return ;
		}
		else
				if(sig == SIGUSR1)
				{
						printf("exit\n");
						exit(SIGUSR1);
				}
}
int output_note()
{
		int fd;
		char buf[1024];
		char time_buf[1024];
		char *pBeack;
		int time;
		fd = open("/proc/uptime",O_RDONLY);
		if(fd== -1)
		{
				perror("read");
				return 0;
		}
		memset(buf,0,sizeof(buf));
		read(fd,buf,sizeof(buf));
		close(fd);

		pBeack = strchr(buf,' ');
		pBeack[0] = '\0';
		time = atoi(pBeack+1)-atoi(buf);
		sprintf(time_buf,"time:%d ",time);
//		printf("%s   %d,%d\n",time_buf,atoi(buf),atoi(pBeack+1));
		fd = open("note",O_WRONLY|O_APPEND|O_CREAT,0666);
		if(fd== -1)
		{
				perror("write");
				return 0;
		}
		write(fd,time_buf,strlen(time_buf));
		close(fd);
		return 0;
}
