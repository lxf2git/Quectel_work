#include"main.h"
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Input error!\n");
		exit(-1);
	}
	pid_t pid=getpid();
	//printf("pid:%d\n",pid);	
	char pid_ch[10];
	memset(pid_ch,0,sizeof(pid_ch));
	sprintf(pid_ch,"%d",pid);
	int fd=open("file.c",O_RDWR|O_CREAT|O_APPEND);
	if(fd<0)
	{
		perror("open_write");
		return FAIL;
	}
	if((write(fd,pid_ch,sizeof(char)*10))<0)
	{
		perror("write_pid_ch");
		return FAIL;		
	}
	if((write(fd,argv[1],sizeof(char)*20))<0)
	{
		perror("write_file_name");
		return FAIL;		
	}
	close(fd);
	act.sa_sigaction = func;
	act.sa_flags = SA_SIGINFO|SA_NODEFER;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR2,&act,NULL);
	while(1)
	{
		;
	}
}
void func(int sig,siginfo_t *info,void *p)
{
	printf("%c",info->si_value.sival_int);
	fflush(stdout);
}
