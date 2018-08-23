#define STOP 0
#define RUN 1
#define SIG_RCV (SIGRTMIN+2)
#define SIG_RCV_END (SIGRTMIN+3)
int stat = STOP;
int flag=0;
char filepath_name[100];

void action_fun(int sig,siginfo_t*info,void *arg)
{
	int i;	
	static int file_index = 0;	
	char *pindex = (char *)&(info->si_int);
	for(i=0;i<4;i++,file_index++)
	{
		filepath_name[file_index] = pindex[i];
		if(filepath_name[file_index]=='\0')
		{
			flag = 1;	
			break;
		}
	}
	if(flag==1)
	{
		raise(SIG_RCV_END);
	}
}

void sig_rcv_end(int sig)
{
	stat = RUN;
}

int main()
{
	printf("pid:%d\n",getpid());

	//注册信号 接收文件名
	
	memset(filepath_name,0,sizeof(filepath_name));

	act.sa_action = action_fun;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);

	sigaction(SIG_RCV,&act,NULL);
	signal(SIG_RCV_END,sig_rcv_end);

	//等待文件名接收完毕
	while(stat==STOP)//说明文件名没传完
	{
		pause();
	}
	fd = open(filepath_name,O_RDONLY);
	if(fd<0)
	{
		//发送错误信息给客户进程
		show_err("open");
	}
	while(1)
	{
		n = read(fd,buf,sizeof(buf));
		if(n<=0)
		{
			break;
		}
		//发送给客户进程
	}

}
