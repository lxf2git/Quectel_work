#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>
#include<stdio.h>

int main()
{
	int fd= open("newfile",O_RDWR);	
	printf("%d",errno);
	printf("open:%s\n",strerror(2));
#if 1
	if(fd<0)
	{
		perror("open");
	}
#endif
	return 0;

}
