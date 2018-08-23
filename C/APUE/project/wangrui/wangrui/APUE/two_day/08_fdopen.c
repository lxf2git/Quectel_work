#include "../apue.h"

int main()
{
	int fid=open("file", O_RDWR);
	FILE *pf=NULL;
	char buf[1024];

	pf=fdopen(fid, "r+");
	if(pf==NULL)
	{
			perror("fdopen");
			return -1;
	}

	memset(buf, 0, sizeof(buf));
	read(fid, buf, 5);
	printf("buf=%s\n", buf);

	memset(buf, 0, sizeof(buf));
	fread(buf, 5, 1, pf);
	printf("buf=%s\n", buf);

	close(fid);
	fclose(pf);
}
