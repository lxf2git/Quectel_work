

#include"../apue.h"
int main()
{
	char buf[20];
	int fd;
	memset(buf,0,sizeof(buf));	
	fd = open("file",O_RDWR);	
	if(fd<0)
	{
		perror("open");
	}
	pid_t pid = fork();
	switch(pid)
	{
		case -1:
				perror("fork");
				exit(-1);      
		case 0:
				read(fd,buf,3);//0123456789   
				printf("child-buf:%s\n",buf);//012
				close(fd);
				exit(0);
		default:
				sleep(1);
				int n = read(fd,buf,3);
				if(n<0)
				{
					perror("read");
					exit(-1);
				}
				printf("par-buf:%s\n",buf);//  345
				close(fd);
				exit(0);//文件指针位置 两个进程共享
		
	}
}
