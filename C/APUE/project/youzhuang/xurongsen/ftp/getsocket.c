#include"aa.h"

int getsocket(struct sockaddr_in selfaddr,int *sockfd)
{
	int ret;

	*sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(*sockfd<0)
	{
		return FAILED;
	}

	if(&selfaddr == NULL)
	{
		selfaddr.sin_family = AF_INET;
		selfaddr.sin_port = htons(7777);
		selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
		ret = bind(*sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
		if(ret<0)
		{
			close(*sockfd);
			return FAILED;
		}
		ret = listen(*sockfd,10);
		if(ret<0)
		{
			close(*sockfd);
			return FAILED;
		}

		return SUC;
	}
	else
	{
		ret = connect(*sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
		if(ret<0)
		{
			close(*sockfd);
			return FAILED;
		}
		return SUC;
	}

}

