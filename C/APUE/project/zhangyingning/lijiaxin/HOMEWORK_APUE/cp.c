#include"apue.h"
#include <errno.h>
int main(int argc,char **argv)
{
		if(argc<2)
		{
				perror("argv");
				return -1;
		}
		int fd_src=open(argv[1],O_RDONLY);
		int fd_dest=open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0777);
		if(fd_src<0)
		{
				perror("open");
				goto ERR;
		}
		char buf[100];
		int ret=0;
		if(fd_dest<0)
		{
				if(errno==EEXIST)
				{
						fd_dest = open(argv[2],O_WRONLY|O_TRUNC);
				}
				else
				{
						perror("open");
						goto ERR;
				}
		}
		while(1)
		{
				memset(buf,0,sizeof(buf));
				ret = read(fd_src,buf,sizeof(buf));
				if(ret==0)
				{
						break;
				}
				write(fd_dest,buf,sizeof(buf));
		}
ERR:
		close(fd_src);
		close(fd_dest);
		return 0;

}
