#include"../apue.h"
int main()
{
	char buf[100]={'\0'};
	int fd;	
	pid_t who;
	printf("input read-pro id:\n");
	scanf("%d",&who);
	getchar();
	for(;;)
	{
		//printf("please input:");	
		scanf("%[^\n]",buf);	
		getchar();
		for(;;)
		{	
			fd = open("data",O_WRONLY|O_CREAT|O_EXCL,0666);
			if(fd>=0)
			{
				break;
			}//另一个程序在读取数据
			printf("data 已存在\n");
			sleep(1);
		}
		write(fd,buf,strlen(buf));
		close(fd);
		kill(who,SIGUSR1);

	}

}
