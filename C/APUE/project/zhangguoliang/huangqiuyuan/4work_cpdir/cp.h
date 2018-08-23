#include"../apue.h"
int cp(char *ar,char *br)
{
	int fid_src=open(ar,O_RDWR);
	int fid_dest=open(br,O_CREAT|O_EXCL|O_RDWR);
		if(fid_dest<0)
		{
			printf("write_source\n");
			return -1;
		}
		char buf[1];
		int i;
		while(1)
		{
		i=read(fid_src,buf,1);
		if(fid_src<0)
		{
			printf("open_source\n");
			goto ERR;
			return -1;
		}
		write(fid_dest,buf,1);
		if(i==0)
		break;
		}
ERR:
	close(fid_src);
ERR1:
	close(fid_dest);
	return 0;
}
