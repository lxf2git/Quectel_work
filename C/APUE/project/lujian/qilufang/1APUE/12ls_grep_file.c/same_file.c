#include"apue.h"
/*************命令行传参，传入(ls | grep "file_name")中的"file_name"*************/

int main(int argc,char **argv)
{
	int i=0;
	char ch;
	int flag=0;
	char buf[20];
	memset(buf,0,sizeof(buf));
	
	char path[100];
	memset(path,0,sizeof(path));

	if(access("file.c",R_OK)==0)
	{
		int fd=open("file.c",O_RDWR);
		read(fd,path,100);
		close(fd);
		unlink("file.c");
		chdir(path);
	}

	if(argc!=2)
	{
		show_err("argv_error");
	}
	FILE * fp_read=fopen("pipe","r");
	if(fp_read==NULL)
	{
		show_err("read_fp");
	}
	while(1)
	{
		if((ch=fgetc(fp_read))==-1)
		{
			break;
		}
		buf[i]=ch;		
		i++;
		if(ch=='\n')
		{
			if(strncmp(buf,argv[1],strlen(argv[1]))==0)
			{
				buf[strlen(buf)]='\0';
				printf("%s",buf);
				flag++;
			}
			i=0;
			memset(buf,0,sizeof(buf));
			
		}

	}
	if(flag==0)
	{
		printf("No file is which you are srearching!\n");
	}
	unlink("pipe");
	return 0;

}
