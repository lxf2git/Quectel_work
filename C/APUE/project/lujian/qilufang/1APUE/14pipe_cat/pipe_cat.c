#include"apue.h"
#define SIGEXIT SIGUSR1
void myexit(int sig)
{
	unlink("pipe");
	exit(0);
}
int main()
{
	mkfifo("pipe",0666);
	char buf_fileName[1024];
	char buf_fileData[1024];
	printf("pid_rcv:%d\n",getpid());
	int fd_openPipe=open("pipe",O_RDWR);
	if(fd_openPipe<0)
	{
		show_err("open_pipe!");
	}
	signal(SIGEXIT,myexit);//收到信号SIGUSR1时退出
	while(1)
	{
		if(fork()==0)
		{
				int fd[2];
				memset(buf_fileName,0,sizeof(buf_fileName));
				int ret_read=read(fd_openPipe,buf_fileName,sizeof(buf_fileName));
				if(ret_read<0)
				{
						show_err("read");
				}
				printf("%s\n",buf_fileName);

				int fd_openFile=open(buf_fileName,O_RDWR);
				if(fd_openFile<0)
				{
					show_err("open_file!");
				}
				mkfifo("pipe_data",0666);
				int fd_filePipe=open("pipe_data",O_WRONLY);
				while(1)
				{
					memset(buf_fileData,0,sizeof(buf_fileData));
					if(read(fd_openFile,buf_fileData,sizeof(buf_fileData))==0)
					{
							break;
					}
					if(write(fd_filePipe,buf_fileData,sizeof(buf_fileData))<0)
					{
						show_err("write_file!");
					}
				}
				exit(0);
		}
		waitpid(-1,NULL,0);
	}
	return 0;

}
