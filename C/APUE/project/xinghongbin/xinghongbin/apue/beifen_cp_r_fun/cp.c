#include"main.h"
int mkdir_destPath(char *path)
{
		char buf[1024];
		char path_srt[1024];
//		for(i=0; path[i]!= '/'|| path[i] != '\0';i++)

		if(path[0]!='/')
		{
				memset(buf,0,sizeof(buf));
				strcpy(path, getcwd(buf,sizeof(buf)));

		}


		printf("%s\n",path);
				mkdir(path,0721);
	
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
