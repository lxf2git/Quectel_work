#include"apue.h"

int main()
{
		DIR *pdir = NULL;
		struct dirent *pdirent = NULL;
		struct stat stat;
		char ch[20]={'\0'};
		char mode;
		int ret;
		printf("输入要查找的目录：\n");
		scanf("%s",ch);
		pdir = opendir(ch);
		if(pdir == NULL)
		{
				perror("opendir");
				exit(-1);
		}
		int fd;
		mkfifo("pipe",0666);
		fd = open("pipe",O_WRONLY);
		printf("打开成功\n");
		while(1)
		{
				pdirent = readdir(pdir);
				if(pdirent == NULL)
				{
					//	perror("readdir");
					//	exit(-1);
						break;
				}
				printf("%s\n",pdirent->d_name);
				write(fd,pdirent->d_name,strlen(pdirent->d_name));
				write(fd,"\n",1);
		}
		close(fd);
		return 0;
}
