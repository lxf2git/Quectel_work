#include "../apue.h"

int main()
{
	int fid;
	char buf[1024];

	fid=open("file", O_RDWR);

	close(0);
	dup(fid);

	memset(buf, 0, sizeof(buf));
	read(fid, buf, 5);
	printf("buf=%s\n", buf);

	memset(buf, 0, sizeof(buf));
	read(0, buf, 5);
	printf("buf=%s\n", buf);

	close(fid);
}
