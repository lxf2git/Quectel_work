#include"apue.h"
int Bpid;
char filename[30];

struct data
{
	char a;
	char b;
	char c;
	char d;
};

union vi
{
		struct data dat;
		int tran;
};

union vi vid;
void sent_pid_to_Bmain()
{
		int fid;
		int a = getpid();
		set_err(fid=open("pid",O_RDWR|O_TRUNC|O_CREAT,0777),"open");
		write(fid,&a,sizeof(&a));
		close(fid);
		printf("sent pid success!\n");
}
void get_Bmainpid()
{
	int fid;
	set_err(fid=open("pid",O_RDONLY),"open");
	read(fid,&Bpid,sizeof(&Bpid));
	close(fid);
	printf("get pid success!\n");
	pause();	

}

void get_filename(int sig,siginfo_t *info,void *p)
{
	strcpy(filename,(char *)&(info->si_value.sival_int));
}


void tran_data()
{
		int fd;
		char ret;
		int sum = 0;
		union sigval v;
		set_err(fd=open(filename,O_RDONLY),"open");
		printf("open file sucess! transport data...\n");
		for(sum=0;read(fd,&ret,1);sum++)
		{
				switch(sum)
				{
						case 0:
								vid.dat.a = ret;
								break;
						case 1:
								vid.dat.b = ret;
								break;
						case 2:
								vid.dat.c = ret;
								break;
						case 3:
								vid.dat.d = ret;
								break;				
				}
				if(sum==3)
				{
						v.sival_int = vid.tran;
						sigqueue(Bpid,SIGUSR2,v);
						sum = -1;
						sleep(1);
				}
		}
		if(sum!=0)
		{
				if(sum==1)
						vid.dat.b = '\0';
				else if(sum==2)
						vid.dat.c = '\0';
				else vid.dat.d = '\0';
				v.sival_int = vid.tran;
				sigqueue(Bpid,SIGUSR2,v);
				sleep(1);
		}
		kill(Bpid,SIGUSR1);

		close(fd);
}

int main()
{
		sent_pid_to_Bmain();
		signal(SIGUSR1,get_Bmainpid);
		
		struct sigaction act;
		act.sa_sigaction = get_filename;
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR2,&act,NULL);
		pause();

		tran_data();	
		return 0;
}
