#include"../apue.h"

int main()
{
	struct sockaddr_in selfaddr,conaddr;
	socklen_t len=sizeof(conaddr);	
	struct epoll_event eparr[10],event;
	int ret,n,num,listenfd,epfd,confd,i;
	char buf[100]={'\0'};

	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		goto ERR;
	}

	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(6111);
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));

	listen(sockfd,5);
	
	epfd = epoll_create(100);
	if(epfd<0)
	{
		goto ERR;
	}
	
	event.events = EPOLLIN;
	event.data.fd = sockfd;
	ret = epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&event);
	if(ret<0)
	{
		perror("epoll_ctl");
		goto ERR;
	}

	while(1)
	{
		n = epoll_wait(epfd,eparr,10,-1);
		if(n<0)
		{
			perror("epoll_wait");
			goto ERR;
		}
		
		for(i=0;i<n;i++)
		{
			if(eparr[i].data.fd==sockfd)
			{
				bzero(&conaddr,sizeof(conaddr));	
				confd = accept(sockfd,(struct sockaddr *)&conaddr,&len);
				if(confd<0)
				{
					perror("confd");
					goto ERR1;
				}
				 printf("%s connect\n",inet_ntoa(conaddr.sin_addr));
				event.events = EPOLLIN;
				event.data.fd = confd;
				ret = epoll_ctl(epfd,EPOLL_CTL_ADD,confd,&event);
				if(ret<0)
				{
					perror("epoll_ctl");
					goto ERR1;
				}


			}
			else if(eparr[i].data.fd!=-1)
			{
				listenfd = eparr[i].data.fd;
				num = read(listenfd,buf,sizeof(buf));
				if(num<=0)
				{
					close(listenfd);
					listenfd = -1;
					continue;
				}
				write(listenfd,buf,num);
			}

		}	
	
	}
ERR1:
	close(sockfd);
ERR:
	close(confd);
	return 0;	

}






