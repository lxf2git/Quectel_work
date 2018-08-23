#include "../apue.h"

void getFileName(char *fileName);
void func(int sig,siginfo_t *info,void *p);
int main(int argc,char *argv[])
{
	if(argc != 2)
	{
		printf("arg error!\n");
		return -1;
	}
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		getFileName(argv[1]);
		printf("%d\n",getpid());
		system("gcc b.c -o b.exe");
		execl("/root/Desktop/myAPUE/9_sigcat/b.exe","b.exe",NULL);
		exit(-1);
	}
	else
	{
		printf("pid:%d ppid:%d\n",pid,getpid());
		struct sigaction act;
		act.sa_sigaction = func;
		act.sa_flags = SA_SIGINFO;
		sigemptyset(&act.sa_mask);
		sigaction(SIGUSR1,&act,NULL);
		while(1)
		{
			pause();
		}
	}
	return 0;
}
void func(int sig,siginfo_t *info,void *p)
{
	int data;
	data = info->si_value.sival_int;
	printf("%c",data);
}
void getFileName(char *fileName)
{
	int fdName;
	char buf[256] = {};
//	getcwd(buf,256);
//	strcat(buf,fileName);
	strcpy(buf,fileName);
	fdName = open("name.txt",O_CREAT|O_RDWR,0777);
	write(fdName,buf,256);
	close(fdName);
}
