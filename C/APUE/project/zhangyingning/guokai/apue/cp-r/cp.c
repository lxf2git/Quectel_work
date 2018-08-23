#include"apue.h"

int cp_file(char *a,char *dest,char *ar2)
{	
//	printf("dest=%s\n",dest);
	char buf[1024];
	int fid_old,fid_new,ret;	
	fid_old = open(dest,O_RDWR);
	if(fid_old<0)
	{
		perror("open old");
		return -1;
	}

	memset(buf, 0, sizeof(buf));
	ret = read(fid_old,buf,sizeof(buf));
	if(ret<0)
	{
		perror("reat");
		goto ERR;
	}
//	printf("ar2=%s\n",ar2);	

	fid_new = open(ar2,O_RDWR|O_EXCL|O_CREAT,0777);
	if(fid_new<0)
	{
		perror("open new");
		return -1;
	}
	ret = write(fid_new,buf,strlen(buf));
	if(ret<0)
	{
		perror("write");
		goto ERR;
	}
ERR:
	close(fid_old);
	close(fid_new);
	return 0;
}
