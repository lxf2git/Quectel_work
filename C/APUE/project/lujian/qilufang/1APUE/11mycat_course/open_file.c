#include"main.h"
int main()
{
	char path[20];
	memset(path,0,sizeof(path));
	char pid_ch[10];
	memset(pid_ch,0,sizeof(pid_ch));
	pid_t pid;
	
	int fd=open("file.c",O_RDWR);
	FILE *fp;
	if(fd<0)
	{
		perror("open_read");
		return FAIL;
	}
	if((read(fd,pid_ch,sizeof(char)*10))<0)
	{
			perror("read_pid_ch");
			return FAIL;		
	}
	if((read(fd,path,sizeof(char)*20))<0)
	{
			perror("read_file_name");
			return FAIL;		
	}
	close(fd);
	//printf("%s\n",pid_ch);
	pid=atoi(pid_ch);
	fp=(fopen(path,"r"));
	if(NULL==fp)
	{
		perror("fopen");
		return FAIL;
	}
	union sigval v;
	while((v.sival_int=fgetc(fp))!=-1)
	{
			sigqueue(pid,SIGUSR2,v);//发送信号和参数
			usleep(50*1000);
	}
	unlink("file.c");

	char command[20];
	memset(command,0,sizeof(command));
	sprintf(command,"kill -9 %s",pid_ch);	
	system(command);
}
