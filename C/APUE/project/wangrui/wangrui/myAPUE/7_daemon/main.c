#include"../apue.h"

int con;
void sigFun(int sig);
int main()
{
	pid_t pid;
	signal(SIGHUP,sigFun);
	signal(SIGUSR1,sigFun);
	pid = fork();
	if(pid == 0)
	{
		FILE * fpid;
		pid_t pid;
		daemon(0,0);
		pid = getpid();
		fpid = fopen("/daemonpid","w");
		fwrite(&pid,sizeof(pid),1,fpid);
		while(1);
	}
	return 0;
}

void sigFun(int sig)
{
	switch(sig)
	{
		case SIGHUP	:
				{
					FILE * fp = NULL;
					char * buf= NULL;
					ssize_t len= 0;
					fp = fopen("/proc/uptime","r");

					getline(&buf,&len,fp);
					fclose(fp);
					fp = fopen("./tmpday","a");
					fwrite(buf,sizeof(buf),1,fp);
					fclose(fp);
					break;
				}
		case SIGUSR1:
				{
					exit(0);
					break;
				}
		default:break;
	}
}
