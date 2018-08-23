#include"apue.h"
//#include<stdio.h>

int main(int argc,char **argv)
{
#if 1
	char buf[1024];
	int fid_,fid__;
	int ret;

	fid_ = open(argv[1], O_RDONLY);
	fid__ = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC);

	FILE *fd=fopen(fid_,"r");
	long file_len;
	file_len = ftell(fd);

	ret=read(fid_, buf, sizeof(buf));
	if(ret<=0)
	{
		perror("read");
		goto ERR;
	}

	while(ret!=0)
	{
		write(fid__, buf, sizeof(buf));
		ret = read(fid_, buf, sizeof(buf));
	}
	write(fid__, buf, sizeof(buf));

ERR:	
	close(fid_);
	close(fid__);
#endif
#if 0
	char ch;
	FILE *fp = fopen(argv[1],"r");
	FILE *fq = fopen(argv[2],"w+");

	while((ch=fgetc(fp))!=EOF)
	{
		fwrite(&ch, 1, 1, fq);
	}

	fclose(fp);
	fclose(fq);
#endif
	return 0;

}
