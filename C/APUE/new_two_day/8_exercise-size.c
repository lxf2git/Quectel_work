#include"../apue.h"

int main(int argc,char **argv)
{
	//目录  opendir readdir closedir chdir mkdir 
	//打开目录 如果普通文件 . stat	 max
	char string[20];
	if(argc!=2)
	{
		sprintf(string,"%s argument\n",argv[0]);
		return -1;
	}

	struct dirent * pdir=NULL;
	struct stat info;
	int ret;
	off_t max=0;
	char str[1024]={'\0'};
	DIR * dp = opendir(argv[1]);
	if(NULL==dp)
	{
		perror("opendir");
		return -1;
	}

	chdir(argv[1]);

	while(1)
	{
		 pdir = readdir(dp);
		 if(NULL==pdir)
		 {
		 	break;
		 }
		 ret = lstat(pdir->d_name,&info);//stat 当前路径找文件
		 if(ret<0)
		 {
		 	perror("stat");
			closedir(dp);
			return -1;
		 }
	
		 if(pdir->d_name[0]=='.')
		 {
		 	continue;
		 }

		 if(S_ISREG(info.st_mode))
		 {
		 	if(max<info.st_size)
			{
				max = info.st_size;
				strcpy(str,pdir->d_name);
			}
		 }

	}

	printf("%s\n",str);
	closedir(dp);
	return 0;

}
