#include"ftp.h"



/*  char *buf 为空，空间够大，用来存放文件内容。*/
int get_server(struct cli_to_ser get_file,char *buf)
{
	

	DIR *pdir = NULL;
	if((pdir = opendir(".")) == NULL)
	{
		perror("opendir");
		return FAIL;
	}
	struct dirent *pdirent = NULL;
	while((pdirent = readdir(pdir)) != NULL)
	{
		if(strcmp(pdirent->d_name,get_file.farg.ftp_get_file) == 0)
		{
			int fp;
			off_t fpl;
			if((fp = open(get_file.farg.ftp_get_file,O_RDWR)) < 0)
			{
				perror("open");
				return FAIL;
			}
			if((fpl = lseek(fp,0,SEEK_END)) < 0)
			{
				perror("lseek");
				return FAIL;
			}
			if(lseek(fp,0,SEEK_SET) < 0)
			{
				perror("lseek");
				return FAIL;
			}
			if(read(fp,buf,fpl*sizeof(buf)) < 0)
			{
				perror("read");
				return FAIL;	
			}
			close(fp);
			closedir(pdir);
			return SUC;
		}
	}
	printf("文件不存在\n");
	return FAIL;
}
