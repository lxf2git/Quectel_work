#include "apue.h"

int main()
{
	char buf[1024];
	int n;
	int fid;
/*
	memset(buf, 0, sizeof(buf));
	n=read(0, buf, sizeof(buf));
	write(1, buf, n);
*/
	close(1);

	fid=open("file", O_RDWR);
	
	memset(buf, 0, sizeof(buf));
	read(fid, buf, 5);
	write(1, buf, 5);
#if 0
	printf("**************************\n");
	memset(buf, 0, sizeof(buf));
	read(0, buf, 5);
	write(1, buf, 5);
#endif
	close(fid);
	return 0;
}
