#include "apue.h"
#define RET_ERR "2"
#define RET_COR "1"//正确返回1，错误返回2
int to_where;
int bd[2];//沟通deal与child的通道
struct recv_to_deal p;
/*char *inet_ntoa(struct in_addr in);
把结构中的IPV4的地址ip地址转成点分十进制字符返回*/
int already_there(in_addr_t tmp)
{
	int i;
	for(i=0;i<MAX_USR;i++)
	if(tmp==now_login[i])
	{	
			to_where=i;
			return INTO_SON;
	}
	return OUT_SON;
}

int is_per()
{
	if((p.to_ser.cmd==LOGIN))
		if(child_log(p.to_ser.user_info))
			return CREAT_NEW_SON;
		else
			return OUT_SON;
	else
		return already_there(p.conaddr.sin_addr.s_addr);

}

void out_son()
{
		char a[2]=RET_ERR;
		printf("input error!\n");
		printf("sendto:%s\n",inet_ntoa(conaddr.sin_addr));
		sendto(sockfd,a,sizeof(a),0,(struct sockaddr*)&conaddr,sizeof(conaddr));

}
void func()
{
	printf("son reading deal!\n");
	bzero(&p,sizeof(p));
	read(bd[0],&p,sizeof(p));//这里对p的值进行改变，不会改变父进程的这个值
	printf("func:%s\n",p.to_ser.ftp_ls_path);
	child(p);
	printf("son read finish!\n");
	//判断功能，分配分文件，执行相应命令!!!!!!!!!!!!!!!!!!!!!!!
}
void I_AM_SON()
{
	close(bd[1]);
	signal(SIGUSR1,func);//当接收到信号时，执行该函数,否则等待
	while(1)pause();
}
void creat_new_son(in_addr_t creat_addr)
{
		int i;
		char a[2]=RET_COR;
		int pid;
		if(already_there(creat_addr)==(int)INTO_SON)
		{
			kill(login_pid[to_where],SIGKILL);
			login_pid[to_where]=EMPTY;
			now_login[to_where]=EMPTY;
		}
		for(i=0;i<MAX_USR;i++)
		{
			if(now_login[i]==EMPTY)
			{
				now_login[i]=creat_addr;//每个地址下面存一个进程号
				if(!(pid=fork()))
					I_AM_SON();
				login_pid[i]=pid;
				printf("创建登录标记!\n");
				sendto(sockfd,a,sizeof(a),0,(struct sockaddr*)&conaddr,sizeof(conaddr));
				break;
			}
		}
}
void into_son()
{
	kill(login_pid[to_where],SIGUSR1);
	//使用管道通讯，子进程接收到信号后，打开管道，接收到数据
	if(p.to_ser.cmd==PUT)
	kill(getppid(),SIGUSR1);
	write(bd[1],&p,sizeof(p));
	int i,status;
	pid_t tmp;
	if((tmp=waitpid(-1,&status,WNOHANG))>1)//此时有子进程结束
	for(i=0;i<MAX_USR;i++)
	if(login_pid[i]==tmp)
	{
			printf("the son has disappear!\n");
			login_pid[i]=EMPTY;
			now_login[i]=EMPTY;
			break;
	}

}
void deal_process()
{
		int ret;
		bzero(now_login,sizeof(now_login));
		bzero(login_pid,sizeof(login_pid));
		close(fd[1]);
		close(bd[0]);
		set_err(pipe(bd),"pipe");
		while(1)
		{
			printf("reading main info!\n");
			bzero(&p,sizeof(p));
			read(fd[0],&p,sizeof(p));
			conaddr=p.conaddr;
			printf("read main finish!\n");
			printf("deal:%s\n",p.to_ser.ftp_ls_path);
			ret=is_per();
			printf("is_per finish,ret=%d\n",ret);
			if(ret==CREAT_NEW_SON)
					creat_new_son(p.conaddr.sin_addr.s_addr);
			else if(ret==INTO_SON)
					into_son(p.conaddr.sin_addr.s_addr);
			else
					out_son();
		}
}
