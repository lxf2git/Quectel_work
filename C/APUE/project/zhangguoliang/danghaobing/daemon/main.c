#include"../apue.h"
int main()
{
	mydaemon(0,0);
	int fd;
	char c = 'a';
	fd = open("zgl.txt",O_CREAT|O_RDWR|O_TRUNC);
	if(fd<0)
	{
			show_err("open");
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
			sleep(1);
	}
	close(fd);
}
