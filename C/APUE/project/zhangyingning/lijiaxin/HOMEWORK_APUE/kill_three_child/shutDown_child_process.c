#include "../apue.h"

int main()
{
		int ret=0;
		int i;
		int count=3;
		char buf[100];
		int fd = open("file",O_RDONLY);
		if(fd<0)
		{
				perror("open");
		}
		while(1)
		{
			i = read(fd,&ret,sizeof(int));
			if(0==i)
			{
					break;
			}
			sprintf(buf,"%.8s%d","kill -9 ",ret);
			system(buf);
		}
		return 0;
}
