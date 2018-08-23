#include"../../apue.h"

int main()
{	
	int ret,n,num,i;
	struct sockaddr_in selfaddr,conaddr;
	char buf[100];
	memset(buf,0,sizeof(buf));
	socklen_t len = sizeof(conaddr);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd < 0)
	{
		myperror("socket");
	}
	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(5678);
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
	if(ret < 0)
	{
		close(sockfd);
		myperror("bind");
	}
	while(1)
	{
			n = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,&len);
			if(n < 0)
			{
					close(sockfd);
					myperror("recvfrom");
			}
			printf("%s send data:%s\n",inet_ntoa(conaddr.sin_addr),buf);
			num = strlen(buf);
			for(i = 0;i<num;i++)
			{
					if(buf[i]>='a'&&buf[i]<='z')
					{
							buf[i] -= 32;
					}
			}
			n = sendto(sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&conaddr,len);
			if(n < 0)
			{
					close(sockfd);
					myperror("sendto");
			}
		//	sleep(5);
	}
	return 0;
}
