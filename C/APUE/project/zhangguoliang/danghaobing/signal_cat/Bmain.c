#include"apue.h"

int Apid;
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
		int a;
};
union vi vid;

int get_Amainpid()
{
	int fid;
	set_err(fid=open("pid",O_RDONLY),"open");
	read(fid,&Apid,sizeof(&Apid));
	close(fid);

}

void set_pid_to_Amain()
{
		int fid;
		int a = getpid();
		set_err(fid=open("pid",O_RDWR|O_TRUNC),"open");
		write(fid,&a,sizeof(&a));
		close(fid);
		kill(Apid,SIGUSR1);
}

void connect()
{
	printf("connecting...\n");
	get_Amainpid();
	set_pid_to_Amain();
	printf("connect sucess!\n");
	sleep(1);
}

void tran_filename()
{
	union sigval v;
	vid.dat.a = 'f';
	vid.dat.b = 'i';
	vid.dat.c = 'l';
	vid.dat.d = 'e';
	v.sival_int=vid.a;	
	sigqueue(Apid,SIGUSR2,v);
	
}

void get_data(int sig,siginfo_t *info,void *p)
{
				printf("%s",(char *)&(info->si_value.sival_int));
				fflush(0);
}

void getout()
{
		exit(0);
}

int main()
{
	connect();
	tran_filename();
	
	struct sigaction act;
	act.sa_sigaction = get_data;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2,&act,NULL);
	signal(SIGUSR1,getout);
	
	while(1)
	pause();
	return 0;
}
