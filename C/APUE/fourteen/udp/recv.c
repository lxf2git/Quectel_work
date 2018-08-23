
#include"../../apue.h"
int main()
{
	struct sockaddr_in selfaddr,conaddr;
	char buf[30];
	int n;
	int ret;
	bzero(buf,sizeof(buf));	
	socklen_t len = sizeof(struct sockaddr_in);
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);	
	if(sockfd<0)
	{
		show_err("socket");
	}

	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_port = htons(5678);
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
	if(ret<0)
	{
		close(sockfd);
		show_err("bind");
	}
	

	n = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,&len);
    printf("ip:%s connet! data:%s \n",inet_ntoa(conaddr.sin_addr),buf);
	return 0;

}



