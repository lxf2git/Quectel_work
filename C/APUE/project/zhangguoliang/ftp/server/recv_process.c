#include "apue.h"
//这里设置存储子函数id
void recv_process(struct recv_to_deal* p)
{
		int ret;
		int len = sizeof(conaddr);
		bzero(&conaddr,len);
		//读传过来的信息
		//创建个管道，来接收deal的返回值
		printf("reading client!\n");
		ret=recvfrom(sockfd,&(p->to_ser),sizeof(struct cli_to_ser),0,(struct sockaddr*)&conaddr,&len);
		to_deal.conaddr=conaddr;
		printf("writing command!\n");
		write(fd[1],p,sizeof(*p));
}
