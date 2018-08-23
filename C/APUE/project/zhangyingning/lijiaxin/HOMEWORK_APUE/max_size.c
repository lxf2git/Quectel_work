#include "apue.h"

int main(int argc,char **argv)
{
		if(2!=argc)
		{
				perror("no argument");
				return -1;
		}
		DIR *pdir=opendir(argv[1]);
		struct dirent *pdirent=NULL;
		struct stat pstat;
		off_t  record=0;
		char str[20];
		int ret=0;
		ret = chdir(argv[1]);
		if(pdir==NULL)
		{
				perror("opendir");
				return -1;
		}
		if(ret<0)
		{
				perror("chdir");
				goto ERR;
		}
		while(1)
		{
				pdirent=readdir(pdir);
				if(pdirent==NULL)
				{
						break;
				}
				if(pdirent->d_name[0]=='.')
				{
						continue;
				}
				
				ret=stat(pdirent->d_name,&pstat);//在当前路径下找文件；
				if(ret<0)
				{
						perror("stat");
						goto ERR;
				}
				if(S_ISREG(pstat.st_mode))
				{
					if(pstat.st_size>record)
					{
						record = pstat.st_size;
						strcpy(str,pdirent->d_name);
					}
				}
		}
		printf("%s\n",str);
		closedir(pdir);
		return 0;
ERR:
		closedir(pdir);
		return -1;
}
