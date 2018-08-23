#include"main.h"
int mkdir_destPath(char *path)
{
		int ret;
		char buf[1024];
		char path_temp[1024];

		if(path[0]!='/')
		{
				sprintf(path_temp,"/%s",path);
				memset(buf,0,sizeof(buf));
				strcpy(path, getcwd(buf,sizeof(buf)));
				strcat(path,path_temp);	

		}

		printf("makedir:%s\n",path);
		ret = mkdir(path,0777);
		if(ret == -1)
		{
				perror("mkdir:");
				return -1;
		}
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
		fd_dest= open(destName,O_RDWR|O_CREAT|O_TRUNC,0666);
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
						break;
				}
				write(fd_dest,buf,ret);
		}
		close(fd_src);
		close(fd_dest);



}
