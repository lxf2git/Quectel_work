#include"apue.h"
/***********命令行传参，传入一个进行ls的地址。*************************/

int main(int argc,char **argv)
{
	if(argc==2)
	{
		int fd=open("file.c",O_CREAT|O_RDWR|O_TRUNC,0666);
		write(fd,argv[1],100);
		chdir(argv[1]);
		close(fd);
	}
	mkfifo("pipe",0666);
	FILE * fp_write=fopen("pipe","w");
	if(fp_write==NULL)
	{
		show_err("fp_write");
	}
	system("ls > pipe");
	fclose(fp_write);
}
