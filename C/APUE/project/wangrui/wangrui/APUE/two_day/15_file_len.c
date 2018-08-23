#include "../apue.h"

int main()
{
	int fid;
	int file_len;

	fid=open("file", O_RDWR);

	file_len=lseek(fid, 0, SEEK_END);
	printf("file_len=%d\n", file_len);

	close(fid);
}
