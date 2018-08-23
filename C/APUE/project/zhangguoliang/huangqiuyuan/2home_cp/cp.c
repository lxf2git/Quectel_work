#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>


int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("%s file_name.\n",argv[0]);
		return -1;
	}
	int fid_src=open(argv[1],O_RDWR);
	int fid_dest=open(argv[2],O_CREAT|O_EXCL|O_RDWR);
		if(fid_dest<0)
		{
			printf("write_source");
			return -1;
		}
		char buf[1];
		int i;
		while(1)
		{
		i=read(fid_src,buf,1);
		if(fid_src<0)
		{
			printf("open_source");
			goto ERR;
			return -1;
		}
		write(fid_dest,buf,1);
		//memset(buf,0,sizeof(buf));
		if(i==0)
		break;
		}
ERR:
	close(fid_src);
ERR1:
	close(fid_dest);
	return 0;
}
