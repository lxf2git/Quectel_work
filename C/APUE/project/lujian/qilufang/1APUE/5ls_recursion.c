/*作业：目录扫描器*/

#define _FILE_OFFSET_BITS 64
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#define N 1024 	//地址最长长度
#define M 200	//文件名最长长度
#define FAIL -1
#define SUC 0
int open_deal(DIR *pdir,char *add)
{
	DIR *dire;
	int ret;
	char new_add[N];
	char add_name[M];
	struct stat s;
   	struct dirent *dirp=NULL;
	bzero(add_name,sizeof(add_name));
	bzero(new_add,sizeof(new_add));
	chdir(add);
	while(1)
	{	
		dirp=readdir(pdir);
		if(NULL==dirp)
		{
			break;
		}
		if(dirp->d_name[0]=='.')
		{
			continue;
		}
		ret=lstat(dirp->d_name,&s);
		if(ret<0)
		{
			perror("lstat");
			return FAIL;
		}
		if(S_ISDIR(s.st_mode))
		{
			dire=opendir(dirp->d_name);
			if(NULL==dire)
			{
				perror("opendir");
				return -1;
			}
			chdir(dirp->d_name);
			getcwd(new_add,sizeof(new_add));
			printf("%s",new_add);
			printf("目录下有：\n");
			open_deal(dire,new_add);
		}
		if(S_ISREG(s.st_mode))
		{
			getcwd(new_add,sizeof(new_add));
		/*	sprintf(add_name,"%s/ %s",new_add,dirp->d_name);
			printf("%s\n",add_name);*/
			printf("      %s\n",dirp->d_name);
		}
	}
	chdir("..");
	printf("此目录完毕\n");
	return SUC;
}
int main(int argc,char **argv)
{
	DIR *pdir;
	if(argc!=2)
	{
		printf("input error!\n");
		return FAIL;
	}
	pdir=opendir(argv[1]);
	if(pdir==NULL)
	{
		perror("opendir");
		return FAIL;
	}
	printf("%s\n",argv[1]);
	printf("目录下有：\n");
	open_deal(pdir,argv[1]);
	return 0;
}
