#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	int fid;
	char buf[1024]="1234567890";
	int ret;

	if(argc!=2)
	{
		printf("%s file_name.\n", argv[0]);

		return -1;
	}

	fid=open(argv[1], O_RDWR);
	if(fid<0)
	{
			perror("open");
			return -1;
	}

	ret=write(fid, buf, strlen(buf));
	if(ret<0)
	{
			perror("write");
			//close(fid);
			//return -1;
			goto ERR;
	}
	//文件位置指针移动到文件的起始位置
	//1 重新打开
	//2 lseek
	ret=lseek(fid, 0, SEEK_SET);
	if(ret<0)
	{
			perror("lseek");
			goto ERR;
	}
	memset(buf, 0, sizeof(buf));
	ret=read(fid, buf, sizeof(buf));
	if(ret<=0)
	{
			perror("read");
			goto ERR;
	}
	printf("read buf=%s\n", buf);
ERR:
	close(fid);
	return 0;



}
