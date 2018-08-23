#include"apue.h"

int show_inode(char *file,int flag)
{

		if(0==flag)
		{
				return 0;
		}
		int ret=0;
		struct stat pstat;
		ret = stat(file,&pstat);
		if(ret<0)
		{
				perror("stat");
		}
		printf("%7d ",pstat.st_ino);
}
