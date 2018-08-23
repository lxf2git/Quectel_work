#include"../../apue.h"
typedef struct file
{
	char name[20];
	char buf[1024];
	char onlypuf[100];
}File_in;
int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("%s file_name\n");
		return -1;
	}
	int ret;
	File_in file_da;
	char buff[100];
	memset(buff,0,sizeof(buff));
	int fd = open("all_pipe",O_RDWR);
	memset(file_da.name,0,sizeof(file_da.name));
	memset(file_da.onlypuf,0,sizeof(file_da.onlypuf));
	strcat(file_da.name,argv[1]);
   	sprintf(buff,"only%d",getpid());
	strcat(file_da.onlypuf,buff);
	ret = write(fd,&file_da,sizeof(file_da));
	if(ret < 0 )
	{
		myperror("write");
	}
	sleep(1);
	int onlyfd = open(buff,O_RDONLY);
	if(onlyfd < 0)
	{
		myperror("open");
	}
	while(1)
	{
			ret = read(onlyfd,&file_da,sizeof(file_da));
			if(ret < 0)
			{
				myperror("read");
			}
			if(0 == ret )
			{
				break;
			}
			printf("%s",file_da.buf);
	}
	close(fd);
	close(onlyfd);
	unlink(buff);
	return 0;
}
