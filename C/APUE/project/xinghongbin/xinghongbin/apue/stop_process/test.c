#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
 #include <sys/types.h>
       #include <sys/stat.h>

int main()
{
		int fd;
		int ret =0;
		int pid;
		fd = open("pid",O_RDWR|O_CREAT|O_TRUNC,0666);
		if(ret == -1)
		{
				perror("open");
				return -1;
		}
		int i;
		for(i=0;i<3;i++)
		{
				if(fork()==0)
				{
						while(i==0)
						{
								sleep(1);
								printf("a\n");
								if(ret == 0)
								{
									pid = getpid();
									printf("%dpid:%d  ppid:%d\n",i,pid,getppid());
									ret = write(fd,&pid,sizeof(int));
									close(fd);
								}
						}
						while(i==1)
						{
								sleep(1);
								printf("b\n");
								if(ret == 0)
								{
									pid = getpid();
									printf("%dpid:%d\n",i,pid);
									ret = write(fd,&pid,sizeof(int));
									close(fd);
								}
						}
						while(i==2)
						{
								sleep(1);
								printf("c\n");
								if(ret == 0)
								{
									pid = getpid();
									printf("%dpid:%d\n",i,pid);
									ret = write(fd,&pid,sizeof(int));
									close(fd);
								}
						}
				}

		}

//		while(wait(NULL)!=-1);
		close(fd);
		return 0;
}
