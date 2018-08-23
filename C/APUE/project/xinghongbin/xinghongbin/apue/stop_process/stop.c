
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
		char buf[1024];
		fd = open("pid",O_RDONLY);
		if(ret == -1)
		{
				perror("open");
				return -1;
		}
		int i;
		for(i=0;i<3;i++)
		{
				ret = read(fd,&pid,sizeof(int));

				sprintf(buf,"kill -9 %d\n",pid);
				printf("%s\n",buf);
				system(buf);
		}
				close(fd);
}
