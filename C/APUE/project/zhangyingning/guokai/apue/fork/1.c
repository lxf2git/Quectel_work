#include"apue.h"

int main()
{
	int fd,i,ret=0;
	int file_char,pid;
	fd = open("file",O_RDWR|O_CREAT|O_TRUNC,0666);
	if(fd<0)
	{
		perror("open");
		return -1;
	}	
	for(i=0;i<3;i++)
	{
		if(fork()==0)
		{	
			while(i==0)
			{
				sleep(1);	
			//	printf("child-getpid:%d parent:%d\n",getpid(),getppid());
				printf("a\n");
				if(ret==0)
				{
					pid = getpid();	
					ret = write(fd,&pid,sizeof(int));
					close(fd);
				}	
			}
			while(i==1)
			{
				sleep(1);
				printf("b\n");
				if(ret==0)
				{
					pid = getpid();	
					ret = write(fd,&pid,sizeof(int));
					close(fd);					
				}	
			}
			while(i==2)
			{
				sleep(1);
				printf("c\n");
				if(ret==0)
				{
					pid = getpid();	
					ret = write(fd,&pid,sizeof(int));
					close(fd);
				}	
			}
		}
	}	
		close(fd);
		system("gcc stop.c -o s");
		//return 0;
}
