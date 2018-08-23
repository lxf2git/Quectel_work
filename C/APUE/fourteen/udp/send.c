#include"../../apue.h"
int main()
{
	printf("%d\n",getpid());	
	int n;	
	struct sockaddr_in conaddr;
	socklen_t len = sizeof(struct sockaddr_in);
	char buf[30];
	bzero(buf,sizeof(buf));	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		show_err("socket");
	}

	bzero(&conaddr,sizeof(conaddr));
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(5678);
	conaddr.sin_addr.s_addr  = inet_addr("192.168.1.200");

	sprintf(buf,"%d say hi friend!\n",getpid());
	n = sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,len);
	if(n<0)
	{
		close(sockfd);
		show_err("sendto");
	}
	return 0;

}
