#include"ftp.h"
int getsocket(struct sockaddr_in *selfaddr,int *sockfd)
{
		int ret;

		*sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(*sockfd<0)
		{
				perror("socket");
				return FAIL;
		}

		if(selfaddr == NULL)
		{
				selfaddr = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
				selfaddr->sin_family = AF_INET;
				selfaddr->sin_port = htons(8888);
				selfaddr->sin_addr.s_addr = htonl(INADDR_ANY);
				ret = bind(*sockfd,(struct sockaddr*)selfaddr,sizeof(struct sockaddr_in));
				if(ret<0)
				{
						perror("bind");
						close(*sockfd);
						return FAIL;
				}
				ret = listen(*sockfd,10);
				if(ret<0)
				{
						perror("listen");
						close(*sockfd);
						return FAIL;
				}

				return SUC;
		}
		else
		{
				ret = connect(*sockfd,(struct sockaddr*)selfaddr,sizeof(struct sockaddr_in));
				if(ret<0)
				{
						close(*sockfd);
						return FAIL;
				}
				return SUC;
		}

}

