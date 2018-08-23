#include"apue.h"
void my_exit(pid_t pid,int sockfd)
{
	write(sockfd,"goodbye",8);
	close(sockfd);

	char com[50];
	bzero(com,sizeof(com));
	sprintf(com,"kill -9 %d",pid+1);
	system(com);	

	puts("欢迎下次使用！");
	exit(0);

}
int main()
{
	struct sockaddr_in selfaddr,conaddr;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		show_err("socket");
	}

	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	selfaddr.sin_port = htons(8888);
	int ret = bind(sockfd,(struct sockaddr *)&selfaddr,sizeof(selfaddr));
	if(ret<0)
	{
		show_err("bind");
	}

	listen(sockfd,10);

	bzero(&conaddr,sizeof(conaddr));
	int len = sizeof(conaddr);
	int confd = accept(sockfd,(struct sockaddr *)&conaddr,&len);

	char buf[50];
	if(fork()==0)
	{
		for(;;)
		{
			bzero(buf,sizeof(buf));
			if(read(confd,buf,sizeof(buf))<0)
			{
				break;
			}
			if(strcmp(buf,"goodbye")==0)
			{
				my_exit(getpid(),confd);
			}
			strcat(buf,"  --client");
			puts(buf);
		}
	}
	else
	{
			while(1)
			{
					printf("Input a str:\n");
					bzero(buf,sizeof(buf));
					scanf("%[^\n]",buf);
					getchar();
					if(write(confd,buf,strlen(buf)+1)<0)
					{
						break;
					}
			}
			close(confd);
	}
	return 0;

}
