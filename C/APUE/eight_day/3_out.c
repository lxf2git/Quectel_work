#include"../apue.h"

void func(int signo)
{
	int fd = open("data",O_RDONLY);
	if(fd<0)
	{
		return;
	}
	char buf[100]={'\0'};
	int len = read(fd,buf,sizeof(buf));
	if(len>0)
	{
		buf[len] = '\0';	
		puts(buf);
	}
	close(fd);
	unlink("data");
}
int main()
{
		signal(SIGUSR1,func);
		printf("pid:%d\n",getpid());

		for(;;)
		{
			sleep(100);
		}
		return 0;

}
