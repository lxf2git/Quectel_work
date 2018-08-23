#include "../include/apue.h"
void epoll_body()
{
	event.events = EPOLLIN|EPOLLET;
	event.data.fd = sockfd;
	epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&event);//监听sockfd,用来连接客户端
	
	event.data.fd=STDIN_FILENO;//先监视输入，因为，服务器想随时查看在线列表
	epoll_ctl(epfd,EPOLL_CTL_ADD,STDIN_FILENO,&event);

	struct epoll_event eparr[20];
	char buf[MAX_SIZE]={0};
	int i,n;
	int listenfd;
	
	while(1)
	{
			n = epoll_wait(epfd,eparr,20,-1);//don't wait
			for(i=0;i<n;i++)
			{
					if(eparr[i].data.fd==STDIN_FILENO)//当服务器想要输入东西时
					{
							pool_add_worker(server_command,NULL);
							/*show_chain();
							read(STDIN_FILENO,buf,sizeof(buf));
							write(STDOUT_FILENO,buf,strlen(buf)+1);
							bzero(buf,sizeof(buf));
							*/
					}
					else if(eparr[i].data.fd==sockfd)//当客户机想要连接时
					{
							pool_add_worker(con_in,NULL);
					}
					else//当客户机发过命令时
					{
					//		printf("感应到！\n");
							listenfd=eparr[i].data.fd;
							pool_add_worker(deal_command,&listenfd);
					}
			}
			
	}
}
