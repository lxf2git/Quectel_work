#include"apue.h"

void func(int sig,siginfo_t *info,void *p)
{
//		printf("**\n");
		//printf("%d\n",info->si_value.sival_int);
        //printf("%d\n",info->si_value.sival_ptr);
		char ch[4]={'\0'};
		int i;
		for(i=3;i>=0;i--)
		{
				ch[i]=info->si_value.sival_int&0xff;
				info->si_value.sival_int = info->si_value.sival_int >> 8 ;
		}
	   	int fd = open("head",O_RDWR);
		if(fd<0)
		{
				perror("head_write");
				exit(-1);
		}
		lseek(fd,0,SEEK_END);
	   	write(fd,ch,4);
		close(fd);
}

void wr_pi(int sig)
{
		char ch[50]={'\0'};
		char ch_vi[5]={'\0'};
		union sigval vil;
		int i;
		int ret,pid;
		vil.sival_int = 0;
		printf("a的id\n");
		scanf("%d",&pid);
		int fd = open("head",O_RDWR);
		if(fd<0)
		{
				perror("head_read");
				exit(-1);
		}
		read(fd,ch,50);
		close(fd);
		int fd_new = open(ch,O_RDWR);
		if(fd_new<0)
		{
				perror(ch);
				exit(-1);
		}
		while(1)
		{
			ret = read(fd_new,ch_vi,4);
			if(ret<=0)
			{
					return;
			}
			for(i=0;i<4;i++)
			{   
			//	printf("***\n");
				vil.sival_int|=ch_vi[i];
			//	printf("%d\n",vil.sival_int);
				if((i+1)%4 == 0)
				{   
						sleep(1);
						sigqueue(pid,SIGSEGV,vil);
						memset(ch_vi,0,4);
						vil.sival_int = 0;
				}   
				else
				{   
						vil.sival_int =vil.sival_int << 8;
				}   
			}   
		}
}

int main()
{
		printf("pid:%d\n",getpid());
		struct sigaction act;
		act.sa_sigaction = func;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1,&act,NULL);
		printf("等待信号2\n");
		signal(SIGUSR2,wr_pi);
		while(1);
		return 0;
}

