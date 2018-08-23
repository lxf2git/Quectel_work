#include"../../apue.h"
int main()
{
	printf("%d\n",getpid());	
	int n;	
	struct sockaddr_in conaddr;
	int on = 1;
	socklen_t len = sizeof(struct sockaddr_in);
	char buf[30];
	bzero(buf,sizeof(buf));	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		show_err("socket");
	}

	setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on));

	bzero(&conaddr,sizeof(conaddr));
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(5678);
	conaddr.sin_addr.s_addr  = inet_addr("192.168.1.255");
int i=0;
while(1)
{	
		i++;
	sprintf(buf,"hi friend %d!\n",i);
	n = sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,len);
	if(n<0)
	{
		close(sockfd);
		show_err("sendto");
	}
	sleep(1);
}
	return 0;

}
