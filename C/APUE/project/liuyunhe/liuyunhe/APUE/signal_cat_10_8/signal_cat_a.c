#include"apue.h"
void re_out(int sig,siginfo_t *info,void *p)
{
	//	printf("&&\n");
		char ch[5]={'\0'};
		int i;
		for(i=3;i>=0;i--)
		{   
				ch[i]=info->si_value.sival_int&0xff;
				info->si_value.sival_int = info->si_value.sival_int >> 8 ; 
		}   
		printf("%s",ch);
		fflush(stdout);
}
int main(int argc,char **argv)
{
		pid_t pid;
		if(argc != 2)
		{
				perror(argv[0]);
				exit(-1);
		}

		printf("b的id\n");
		scanf("%d",&pid);
		union sigval vil;
		int i;
		vil.sival_int = 0;
		for(i=0;argv[1][i]!='\0';i++)
		{
	//			printf("***\n");
			vil.sival_int|=argv[1][i];
	//		printf("%d\n",vil.sival_int);
			if((i+1)%4 == 0)
			{
					sleep(1);
			sigqueue(pid,SIGUSR1,vil);
			vil.sival_int = 0;
			}
			else
			{
			vil.sival_int =vil.sival_int << 8;
			}
		}
		if(i%4!=0)
		{
				for(i=i%4+1;i<4;i++)
				{						
						vil.sival_int =vil.sival_int << 8;
				}
					sleep(1);
				sigqueue(pid,SIGUSR1,vil);
		}
				sleep(1);
				kill(pid,SIGUSR2);
		printf("pid:%d\n",getpid());
		struct sigaction act;
		act.sa_sigaction = re_out;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGSEGV,&act,NULL);
		while(1);
		printf("\n");
		return 0;
}
