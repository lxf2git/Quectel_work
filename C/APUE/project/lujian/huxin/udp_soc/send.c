#include"../../apue.h"

int main()
{
	int n;
	struct sockaddr_in conaddr;
	socklen_t len = sizeof(conaddr);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		myperror("socket");
	}
	char buf[100];
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(5678);
	conaddr.sin_addr.s_addr = inet_addr("192.168.1.42");
	while(1)
	{
			memset(buf,0,sizeof(buf));
			printf("please input char string\n");
			scanf("%s",buf);
			n = sendto(sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&conaddr,len);
			if(n < 0)
			{
					close(sockfd);
					myperror("sendto");
			}
			sleep(1);
			bzero(buf,sizeof(buf));

			n = recvfrom(sockfd,buf,sizeof(buf),0,NULL,NULL);
			puts(buf);
	}
	close(sockfd);	

	return 0;
}
