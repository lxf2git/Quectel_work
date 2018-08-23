#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int copy_str(char *fileName,char *destName);
int main(int argc ,char **argv)
{
		int fd;
		if (argc != 3)
		{
				printf("use error....\n");
				exit(-1);
		}
		copy_str(argv[1],argv[2]);
		return 0;

}
int copy_str(char *fileName,char *destName)
{
		int fd_src;
		int fd_dest;
		char buf[1024];
		int ret;
		fd_src = open(fileName,O_RDONLY);
		if(-1 == fd_src)
		{
				perror("src");
				exit(-1);
		}
		fd_dest= open(destName,O_RDWR|O_CREAT|O_TRUNC,0777);
		if(-1 == fd_dest)
		{
				perror("dest");
				close(fd_src);
				exit(-1);
		}
		while(1)
		{
				memset(buf,0,sizeof(buf));
				ret = read(fd_src,buf,sizeof(buf));
				if(ret<=0)
				{
						perror("read");
						return 0;
				}
				write(fd_dest,buf,ret);
		}



}
