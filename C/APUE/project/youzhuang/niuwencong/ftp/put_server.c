#include"ftp.h"



int put_server(struct cli_to_ser put_file,char *buf)
{
	DIR *pdir;
	if((pdir=opendir(".")) == NULL)
	{
		perror("opendir");
		return FAIL;
	}
	struct dirent *pdirent;
	int fp = 0;
	while((pdirent=readdir(pdir)) != NULL)
	{
		if(strcmp(pdirent->d_name,put_file.farg.ftp_put_file) == 0)
		{

#if 1
			printf("文件已存在\n");	
			return FAIL;
#if 0
			if((fp=open(put_file.farg.ftp_put_file,O_RDWR|O_TRUNC)) < 0)
			{
				perror("open");
				return FAIL;
			}
#endif
		}
	}
	if(0 == fp)
	{
		if((fp=open(put_file.farg.ftp_put_file,O_CREAT|O_RDWR,0666)) < 0)
		{
			perror("open");
			return FAIL;
		}
	}	
	if(write(fp,buf,strlen(buf)) < 0)
	{
		perror("write");
		return FAIL;
	}
	close(fp);
	closedir(pdir);
	return SUC;
}
