#include<stdio.h>
#include<signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
void talk_b(int sign);
void talk_main(int sign);

int main()
{
		int fd;
		int pid,i;
		sigset_t newset;


		if(fork()==0)
		{
				signal(SIGUSR2,talk_b);
				sigemptyset(&newset);
				sigaddset(&newset,SIGUSR1);
				sigprocmask(SIG_BLOCK,&newset,NULL);
				kill(0,SIGUSR1);
		}
		else
		{

				signal(SIGUSR1,talk_main);
				sigemptyset(&newset);
				sigaddset(&newset,SIGUSR2);
				sigprocmask(SIG_BLOCK,&newset,NULL);
		}

		while(1)
		{
				;
		}

}
void talk_main(int sign)
{
		printf("i am main hello\n");
		write_file();
		sleep(2);
		printf("send %d\n",SIGUSR2);
		kill(0,SIGUSR2);

}
void talk_b(int sign)
{
		printf("i am b hello\n");
		read_file();
		//		getchar();
		sleep(2);
		printf("send %d\n",SIGUSR1);
		kill(0,SIGUSR1);
}
int read_file()
{
		int fd,ret;
		char buf[1024];
		memset(buf,0,sizeof(buf));
		fd = open("file",O_RDONLY);
		if(fd == -1)
		{
				perror("read_open");
				exit(-1);
		}
		ret = read(fd,buf,sizeof(buf));
		if(ret <0)
		{
				perror("read_read");
				return 0;
		}
		printf("buf:%s\n",buf);
		close(fd);
}
int write_file()
{
		int fd,ret;
		char buf[1024];
		printf("input:\n");
		scanf("%[^\n]",buf);
		getchar();
		fd = open("file",O_WRONLY|O_TRUNC|O_CREAT,0666);
		if(fd == -1)
		{
				perror("write_open");
				exit(-1);
		}
		ret = write(fd,buf,strlen(buf));
		if(ret <0)
		{
				perror("write_write");
				return 0;
		}
		close(fd);
}
