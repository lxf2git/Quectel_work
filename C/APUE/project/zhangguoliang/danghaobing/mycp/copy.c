#include"copy.h"
void copy_file(char *source,char *dest)
{
	int fid = open(source,O_RDONLY);
	if(fid<0)
	{
			printf("%s:%s\n",source,strerror(errno));
			goto ERR;
	}
	int fidc = open(dest,O_CREAT|O_EXCL|O_RDWR,0777);
	if(fidc<0)
	{
			printf("%s:%s\n",dest,strerror(errno));
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
}

