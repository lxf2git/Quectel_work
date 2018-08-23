#include"apue.h"

int main(int argc,char**argv)
{
	char buf[1024];
	int fid_old,fid_new,ret;	
	if(argc!=3)
	{
		printf("%s old_file_name %snew_file_name\n",argv[0]);
		return -1;
	}
	fid_old = open(argv[1],O_RDWR);
	if(fid_old<0)
	{
		perror("open old");
		return -1;
	}
	fid_new = open(argv[2],O_RDWR|O_EXCL|O_CREAT,0777);
	if(fid_new<0)
	{
		perror("open new");
		return -1;
	}
//	ret = lseek(fid_old,0,SEEK_SET);
//	if(ret<0)
//	{
//		perror("lseek");
//		goto ERR;
//	}
	memset(buf, 0, sizeof(buf));
	ret = read(fid_old,buf,sizeof(buf));
	if(ret<0)
	{
		perror("reat");
		goto ERR;
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
