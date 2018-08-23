#include"apue.h"
struct sockaddr_in read_info(int sockfd)
{

	struct sockaddr_in conaddr;
	bzero(&conaddr,sizeof(conaddr));

	int len = sizeof(conaddr);
 
	char buf[1024];
	bzero(buf,sizeof(buf));

	while(1)
	{
		int ret = recvfrom(sockfd,buf,sizeof(buf),
		MSG_DONTWAIT,(struct sockaddr *)&conaddr,&len);
		if(ret>0)
		{
			puts(buf);
			break;
		}
		else
		{
			puts("There is no information!");
			break;
		}
	}
	return conaddr;
}
