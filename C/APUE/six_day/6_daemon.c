#include"../apue.h"
int main()
{
	int fd;
	char c = 'a';	
	mydaemon();//daemon(0,0);
	fd = open("/tmp/daemon",O_CREAT|O_RDWR);	
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
		sleep(2);
	}
	close(fd);
	return 0;

}
