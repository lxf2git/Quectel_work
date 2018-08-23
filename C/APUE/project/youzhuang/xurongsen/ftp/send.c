#include"rev_snd.h"
int main()
{
	printf("%d\n",getpid());	
	int n;	
	char buf_ip[20];
	struct sockaddr_in conaddr;
	socklen_t len = sizeof(struct sockaddr_in);
	char buf[30],rcv_buf[30];
	bzero(buf,sizeof(buf));	
	bzero(rcv_buf,sizeof(rcv_buf));	
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		show_err("socket");
	}

	printf("请输入要连接的服务器的ip:");
	//scanf("%s",buf_ip);
	sprintf(buf_ip,"192.168.1.35");

	bzero(&conaddr,sizeof(conaddr));
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(5678);
	conaddr.sin_addr.s_addr  = inet_addr(buf_ip);//("192.168.1.35");

	while(1)
	{
			printf("请输入数据（#退出):");
			scanf("%s",buf);
		//	sprintf(buf,"%c",'#');
			printf("\n");
	//		sprintf(buf,"%d say hi friend!\n",getpid());
			n = sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&conaddr,len);
			if(n<0)
			{
				//	close(sockfd);
					show_err("sendto");
			}
			if(strcmp(buf,"#")==0)
			{
				break;
			}

			n = recvfrom(sockfd,rcv_buf,sizeof(rcv_buf),0,NULL,0);
			puts(rcv_buf);
			if(strcmp(rcv_buf,"#")==0)
			{
				break;
			}
			bzero(rcv_buf,sizeof(rcv_buf));
	}
	close(sockfd);
	return 0;

}
