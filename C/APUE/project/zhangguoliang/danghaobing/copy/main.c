#include"apue.h"
int main(int argc,char **argv)
{
	if(argc!=3)
	{
			printf("%s file_name file_copy\n",argv[0]);
			return -1;
	}
	int fid = open(argv[1],O_RDONLY);
	if(fid<0)
	{
			printf("%s:%s\n",argv[1],strerror(errno));
			goto ERR;
	}
	int fidc = open(argv[2],O_CREAT|O_EXCL|O_RDWR,0777);
	if(fidc<0)
	{
			printf("%s:%s\n",argv[2],strerror(errno));
			goto ERR;
	}
	char rchar[255];
	while(read(fid,&rchar,250))
	{	
		if(write(fidc,rchar,250)<0)
		{
				perror("write");
				goto ERR;
		}
	}
ERR:
	close(fid);
	close(fidc);
	return 0;
}

