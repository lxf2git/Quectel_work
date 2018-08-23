#include"../../apue.h"

int main()
{
		struct sockaddr_in seraddr,conaddr;
		bzero(&seraddr,sizeof(seraddr));
		bzero(&seraddr,sizeof(conaddr));
	
		char buf[50];
		bzero(buf,sizeof(buf));

		int confd,sockfd,ret,i=0;
		socklen_t len = sizeof(conaddr);

		sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(sockfd<0)
		{
				perror("sockfd");
				exit(-1);
		}

		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(8888);
		seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
		ret = bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
		if(ret<0)
		{
				perror("bind");
				close(sockfd);
				exit(-1);
		}

		ret = listen(sockfd,1);
		if(ret<0)
		{
				perror("listen");
				close(sockfd);
				exit(-1);
		}

		 confd = accept(sockfd,(struct sockaddr *)&conaddr,&len);
#if 0
		read(confd,buf,sizeof(buf));
		while(buf[i]!='\0')
		{
				if(buf[i]>96&&buf[i]<123)
				{
						buf[i] = buf[i]-32;
				}
				i++;
		}
		write(confd,buf,sizeof(buf)+1);
#else
		read(confd,buf,sizeof(buf));
		write(confd,buf,sizeof(buf));
#endif
		return 0;
}
