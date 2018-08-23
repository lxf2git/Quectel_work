#include"main.h"
int main()
{
/*	pid_t pid = fork();
	if(pid<0)
	{
		perror("fork");
		exit(-1);
	}
	chdir("/");
	if(pid==0)
	{
		setsid();
		int de=open("/dev/null",O_RDWR);
		dup2(de,0);
		dup2(de,1);
		dup2(de,2);
*/
		mydaemon(0,0);
		int fd=open("/tmp/daemon",O_CREAT|O_TRUNC|O_RDWR);
		show_err(fd,"open");
		char c='a';
		while(1)
		{
			write(fd,&c,1);
			write(1,&c,1);
			if(c=='z')
			{
				c='a'-1;
			}
			c++;
			sleep(1);
		}
		close(fd);
//		close(de);
//	}

	return 0;
}
