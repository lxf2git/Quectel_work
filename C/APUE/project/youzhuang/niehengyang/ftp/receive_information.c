#include "main.h"

int receive_information(char *data,int sockfd)
{
	 bzero(&conaddr,sizeof(conaddr));
         conaddr.sin_family = AF_INET;
         conaddr.sin_port = htons(6111);
         conaddr.sin_addr.s_addr = inet_addr(argv[1]);
         ret = connect(sockfd,(struct sockaddr*)&conaddr,sizeof(conaddr));
         if(ret<0)
         {
         	close(sockfd);
                perror("connect");
         }
         confd = sockfd;
         break;

	 write(1,buf,sizeof(buf));
}
