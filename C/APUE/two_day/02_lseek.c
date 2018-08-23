#include "apue.h"

int main()
{
	int fid;
	int ret;
	char ch='\0';

	fid=open("file", O_RDWR);
	if(fid<0)
	{
			perror("open");
			return -1;
	}

	ret=lseek(fid, (off_t)6*(off_t)1024*(off_t)1024*(off_t)1024, SEEK_SET);
	if(ret<0)
	{
			perror("lseek");
			goto ERR;
	}
	
	write(fid, &ch, sizeof(char));
ERR:
	close(fid);
	return 0;
}
