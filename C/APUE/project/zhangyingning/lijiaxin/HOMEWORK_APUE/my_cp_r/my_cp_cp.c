#include"apue.h"

int my_cp(char *str1,char *str2)
{
		char dest_buf[100]={'\0'};
		char add_tmp[2]="/";
		strcpy(dest_buf,str2);
		strcat(dest_buf,add_tmp);
		strcat(dest_buf,str1);
//		printf("dest:%s\n",dest_buf);
		int fd_src=open(str1,O_RDONLY);
		int fd_dest=open(dest_buf,O_CREAT|O_EXCL|O_WRONLY,0666);
		if(fd_src<0)
		{
				perror("open1");
				goto ERR;
		}
		char buf[100];
		int ret=0;
		if(fd_dest<0)
		{
				if(errno==EEXIST)
				{
						fd_dest = open(dest_buf,O_WRONLY|O_TRUNC);
				}
				else
				{
						perror("open2");
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
