#include"apue.h"
int main()
{
		int fanhui=0;
		pid_t pid;
		int fd = open("file",O_RDWR);
		pid_t child;
		while(1)
		{
			fanhui = read(fd,&pid,4);
			if(0 == fanhui)
			{
					break;
			}
			printf("%d\n",pid);
			//child = waitpid(pid,NULL,WNOHANG);
			//printf("%d结束\n",child);
			kill(pid,1);
		}
		return 0;
}

