#include"../apue.h"
int my_daemon(int nochdir,int noclose);
int main()
{
		int fd;
		char c = 'a';
		my_daemon(0,0);
	//	daemon(0,0);
		fd = open("/tmp/daemon",O_CREAT|O_RDWR);
		if(fd<0)
		{
				perror("open");
		}
		while(1)
		{
				write(fd,&c,1);
				write(1,&c,1);
				if(c=='z')
				{
						c = 'a'-1;
				}
				c++;
				sleep(2);
		}
		close(fd);
		return 0;
}
