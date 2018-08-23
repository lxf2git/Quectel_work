#include "../apue.h"

int main(int argc, char **argv)
{
		int fid;

		umask(0);

		fid=open(argv[1], O_CREAT, 0777);
		if(fid<0)
		{
				perror("open");
				return -1;
		}

		close(fid);
		return 0;
}
