#include "apue.h"

int main()
{
		int fid;
		int ret;
		char ch;

		fid=open("file", O_RDWR);//3
		printf("fid=%d\n", fid);

		while(1)
		{
			ret=read(fid, &ch, sizeof(char));
			if(ret==0)
			{
					break;
			}
			printf("[fid=%d]ch=%c\n",fid, ch);
			sleep(1);
		}

		close(fid);

		fid=open("file", O_RDWR);//3
		printf("2:fid=%d\n", fid);
		close(fid);


		return 0;
}
