#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define SUC 0
#define FAIL -1
int copy(char *dest,const char *src);
int main(int argc, char **argv)
{
		if(argc!=3)
		{
				printf("%s file name\n", argv[0]);
				return -1;
		}
		if(copy(argv[2], argv[1])<0)
		{
				printf("copy fail\n");
		}
		else
		{
				printf("copy success\n");
		}
		return 0;
}

int copy(char *dest, const char *src)
{
		int src_fid,dest_fid;
		char ch[1024];
		src_fid=open(src, O_RDONLY);
		dest_fid=open(dest, O_CREAT|O_WRONLY|O_EXCL, 0666);
		if(src_fid<0)
		{
				perror("open");
				return FAIL;
		}
		if(dest_fid<0)
		{
				printf("cp: overwrite '%s'", dest);
				scanf("%c", ch[0]);
				getchar();
				if('Y'==ch[0]||'y'==ch[0])
				{
						dest_fid=open(dest, O_WRONLY);
				}
				else
				{
						return FAIL;
				}
		}
		while(read(src_fid, ch, 1024)>0)
		{
				write(dest_fid, ch, strlen(ch));
		}
		close(src_fid);
		close(dest_fid);
		return SUC;
}
