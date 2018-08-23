#include "apue.h"

void funstop()
{
		printf("stop recv!\n");
		sem.sem_op=-1;
		semop(semid,&sem,1);
		printf("stop over!\n");

}
int main()
{

		bzero(&to_deal,sizeof(to_deal));
		set_err(sockfd=socket(AF_INET,SOCK_DGRAM,0),"socket");
		struct sockaddr_in selfaddr;
		socklen_t len=sizeof(struct sockaddr_in);
		bzero(&selfaddr,len);
		selfaddr.sin_family=AF_INET;
		selfaddr.sin_addr.s_addr=htonl(INADDR_ANY);
		selfaddr.sin_port=htons(8888);
		set_err(bind(sockfd,(struct sockaddr*)&selfaddr,len),"bind");
		signal(SIGUSR1,funstop);
		semid=semget((key_t)0x123,1,IPC_CREAT|0666);
		semctl(semid,0,SETVAL,0);
		sem.sem_num=0;
		sem.sem_flg=0;
		set_err(pipe(fd),"pipe");
		if(!fork())
		{
			deal_process();
		}
		close(fd[0]);
		while(1)//循环接收客户端请求
		{
			recv_process(&to_deal);//接收的时候期待阻塞
			
		}
}

