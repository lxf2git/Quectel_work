#include"./apue.h"




int main()
{
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd == -1)
		{
				perror("socket");
				exit(-1);
		}
		struct sockaddr_in saddr,raddr;
		bzero(&saddr,sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_addr.s_addr = inet_addr("192.168.1.200");
		saddr.sin_port = htons(8886);
		
		bzero(&raddr,sizeof(raddr));
		raddr.sin_family = AF_INET;
		raddr.sin_addr.s_addr = inet_addr("192.168.1.200");
		raddr.sin_port = htons(8888);
		int ret = bind(sockfd,(struct sockaddr *)&raddr,sizeof(raddr));
		if(ret == -1)
		{
				perror("bind");
				exit(-1);
		}
	//	saddr.sin_port = htons(8888);

		char buf[1024];
		bzero(buf,sizeof(buf));
		read(0,buf,sizeof(buf));
//		while(1)
//		{
				
				int n = sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&saddr,sizeof(saddr));
	//			printf("n:%d",n);


		//		if(fork()==0)
		//		{
						bzero(buf,sizeof(buf));
						bzero(&raddr,sizeof(raddr));
						socklen_t len = sizeof(raddr);
						recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&raddr,&len);
						puts(buf);
						//exit(0);
		//		}
//		}
}
