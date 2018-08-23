#include"../../apue.h"
//1.socket 2.bind  3.list 4 accept 5 read/write  6 close

int main()
{
	struct sockaddr_in selfaddr,conaddr;	
	int ret,confd;
	socklen_t len = sizeof(conaddr);
	char buf[50],msg[30];
	bzero(buf,sizeof(buf));

	int sockfd = socket(AF_INET,SOCK_STREAM,0);	
	if(sockfd<0)
	{
		show_err("socket");
	}
	
	bzero(&selfaddr,sizeof(selfaddr));
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_addr.s_addr =htonl(INADDR_ANY); 
	//一般用0表示本机地址 
	selfaddr.sin_port = htons(8888);
	ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
	if(ret<0)
	{
		close(sockfd);
		show_err("bind");
	}

	listen(sockfd,10);
//反复等待客户连接

for(;;)
{
	bzero(&conaddr,sizeof(conaddr));
	bzero(&msg,sizeof(msg));
	 confd = accept(sockfd,(struct sockaddr*)&conaddr,&len);
	if(confd<0)
	{
		continue;
	}

	 read(confd,buf,sizeof(buf));
	 puts(buf);
	 printf("%s到此一游\n",inet_ntoa(conaddr.sin_addr));

	 sprintf(msg,"your ip %s welcome to network\n",inet_ntoa(conaddr.sin_addr));
	 write(confd,msg,strlen(msg)+1);
	 close(confd);
}
 	 return 0;

}
