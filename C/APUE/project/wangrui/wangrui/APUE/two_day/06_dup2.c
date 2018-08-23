#include "../apue.h"

int main()
{
		int fid,newFid;
		char buf[1024];

		fid=open("file", O_RDWR);
		if(fid<0)
		{
				perror("open");
				return -1;
		}

		printf("fid=%d\n", fid);//3
		newFid=dup2(fid, 0);
		printf("fid=%d\n", fid);//3
			
		memset(buf, 0, sizeof(buf));
		read(fid, buf, 5);
		printf("buf=%s\n", buf);

		memset(buf, 0, sizeof(buf));
		read(0, buf, 5);
		printf("buf=%s\n", buf);

			
		close(fid);

		return 0;
}
