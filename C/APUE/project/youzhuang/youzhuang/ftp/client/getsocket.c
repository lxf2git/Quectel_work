#include"ftp.h"
int getsocket(struct sockaddr_in *dest_addr,int *sockfd)
{
		int ret;
		struct sockaddr_in *selfaddr;
		*sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(*sockfd<0)
		{
				perror("socket");
				return FAIL;
		}

	
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
	
	       
		{
				ret = connect(*sockfd,(struct sockaddr*)dest_addr,sizeof(struct sockaddr_in));
				if(ret<0)
				{
						close(*sockfd);
						return FAIL;
				}
				return SUC;
		}

}

