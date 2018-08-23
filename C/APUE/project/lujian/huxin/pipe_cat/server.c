#include"../../apue.h"
typedef struct file
{
	char name[20];
	char buf[1024];
	char onlypuf[100]; 
}File_in;
int main()
{
	int fd;	
	ssize_t ret;
	File_in file_da;
	mkfifo("all_pipe",0644);
	fd = open("all_pipe",O_RDWR);
	while(1)
	{
		ret= read(fd,&file_da,sizeof(file_da));
		if (ret < 0)
		{
			myperror("read"); 
		}
		pid_t pid = fork();
		if(pid< 0)
		{
			myperror("fork");
		}
		if(pid == 0)
		{
			int fd = open(file_da.name,O_RDONLY);
			mkfifo(file_da.onlypuf,0644);
			int onlyfd = open(file_da.onlypuf,O_WRONLY);
			while(1)
			{

				memset(file_da.buf,0,sizeof(file_da.buf));
				ret = read(fd,file_da.buf,sizeof(file_da.buf));
				if(ret < 0)
				{
					myperror("sonread");
				}
				if(ret == 0)
				{
					break;
				}
				ret = write(onlyfd,&file_da,sizeof(file_da));
				if(ret < 0)
				{
					myperror("onlywrite");
				}
			}
			close(onlyfd);
			exit(0);
		}
		wait(NULL);
	}
	return 0;
}
