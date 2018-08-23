#include"../apue.h"
int main()
{
		int i=0;
		struct sockaddr_in sndaddr;
		socklen_t addr_len = sizeof(struct sockaddr_in);
		char buf[30];
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd<0)
		{
			show_err("socket");
		}

		bzero(&sndaddr,sizeof(sndaddr));
		sndaddr.sin_family = AF_INET;
		sndaddr.sin_port = htons(1234);
		sndaddr.sin_addr.s_addr = inet_addr("224.0.0.8");
	while(1)
	{	
		bzero(buf,sizeof(buf));
		sprintf(buf,"hello");
		i++;

		sendto(sockfd,buf,sizeof(buf)+1,0,(struct sockaddr*)&sndaddr,addr_len);
		sleep(1);
	
	}	
	return 0;

}
