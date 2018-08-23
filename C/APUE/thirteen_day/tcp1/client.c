#include"../../apue.h"
//  ./a.out serverip serverport
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		show_err("argument");
	}	

	char buf[30];
	bzero(buf,sizeof(buf));
	struct sockaddr_in seraddr;
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		show_err("socket");
	}

	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(atoi(argv[2]));
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
	{
		close(sockfd);
		show_err("connect");
	}

for(;;)
{	
	sprintf(buf,"%d say hi to server\n",getpid());
	write(sockfd,buf,strlen(buf)+1);
	close(sockfd);
}
	return 0;


}


