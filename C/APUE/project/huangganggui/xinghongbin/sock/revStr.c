#include"./apue.h"
void atoA(char *data);




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
		bzero(&raddr,sizeof(raddr));
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(8888);
		saddr.sin_addr.s_addr = inet_addr("192.168.1.200");

		bzero(&raddr,sizeof(saddr));
		raddr.sin_family = AF_INET;
		raddr.sin_port = htons(8886);
		raddr.sin_addr.s_addr = htonl(INADDR_ANY);
		
		char buf[1024];
		bzero(buf,sizeof(buf));
		int ret = bind(sockfd,(struct sockaddr *)&raddr,sizeof(raddr));
		if(ret == -1)
		{
				perror("bind");
				exit(-1);
		}
		//while(1)
		//{
				bzero(buf,sizeof(buf));
				socklen_t len = sizeof(raddr);
				int n = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&raddr,&len);
				printf("%d\n",n);
				if(n == -1)
				{
						perror("recv");
						exit(-1);
				}
				//if(n == 0)
				///		break;
				puts(buf);
				atoA(buf);
				puts(buf);
			//	getchar();
		//}
		
		puts("++++++++++++++++");
		n = sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&saddr,sizeof(saddr));
	puts("++++++++++++++++");	
printf("n:%d\n",n);
		


}

void atoA(char *data)
{
		int i;
		for(i=0;i<strlen(data);i++)
				if(data[i]>=97 && data[i]<=122)
						data[i]-=32;
		
}
