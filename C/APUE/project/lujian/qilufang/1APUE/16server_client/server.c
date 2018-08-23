#include"apue.h"
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

	bzero(buf,sizeof(buf));
	if(read(confd,buf,sizeof(buf))<0)
	{
			show_err("read_srever");		
	}
	int index=0;
	while(1)
	{
			if(buf[index]=='\0')
			{
					break;
			}
			if(buf[index]>96&&buf[index]<123)
			{
					buf[index]-=32;
			}
			index++;
	}
	if(write(confd,buf,strlen(buf)+1)<0)
	{
			show_err("write_server!");
	}

	close(confd);
 	close(sockfd);      
	return 0;

}
