#include"cs.h"

void fun(int sig)
{
		wait(NULL);
}

int main()
{
		int i;
		char filename[256],cpname[10];
		int pfd,pid,len;
		signal(SIGUSR1,fun);
		mkfifo("pipe", 0666);
		pfd = open("pipe", O_RDONLY);
		while(1)
		{
				memset(cpname, 0, sizeof(cpname));
				memset(filename, 0, sizeof(filename));
				len=read(pfd, cpname, sizeof(cpname));
				if(len==0)
				{
						continue;
				}
				printf("!!\n",len);
				read(pfd, filename, sizeof(filename));
				pid = fork();
				if(pid == 0)
				{
						char data[1024];
						int cffd,cpfd;
						cpfd = open(cpname, O_WRONLY);
						cffd = open(filename, O_RDONLY);
						while(1)
						{
								memset(data, 0, sizeof(data));
								len = read(cffd, data, sizeof(data));
								if(len<=0)
								{
										break;
								}
								write(cpfd, data, sizeof(data));
						}
						kill(getppid(), SIGUSR1);
						exit(0);
				}
		}
		return 0;
}
