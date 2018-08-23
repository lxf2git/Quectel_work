#include"apue.h"
//*********递归函数***********
int dir_guc(char *argv)
{
		DIR *pdir=NULL;
		int ret=0;
		struct dirent *pdirent = NULL;
		struct stat stat;
		char buf[100]={'\0'};
		pdir = opendir(argv);
		if(NULL == pdir)
		{
				perror(argv);
				return 0;
		}
		else
		{
				while(1)
				{
						pdirent = readdir(pdir);
						if(NULL == pdirent)
						{
								goto ERR;
						}
						chdir(argv);
						ret = lstat((pdirent->d_name),&stat);
					//	printf("###:%s\n",pdirent->d_name);
						if(-1 == ret)
						{
								perror("lstat");
								goto ERR;
						}
						if('.' == pdirent->d_name[0])
						{
								continue;
						}
						if(S_ISDIR(stat.st_mode))
						{
								chdir(pdirent->d_name);
								memset(buf,0,sizeof(buf));
								getcwd(buf,sizeof(buf));
								printf("*%s\n",buf);
								dir_guc(buf);
							//	printf("argv   :%s\n",argv);
						}
						if(S_ISREG(stat.st_mode))
						{
								memset(buf,0,sizeof(buf));
								getcwd(buf,sizeof(buf));
								printf("%s %s\n",buf,pdirent->d_name);
						}
				}
		}
ERR:
		closedir(pdir);
		return 0;
}
