#include"apue.h"
#include"microblog.h"










void Connect_Server(struct sockaddr_in *seraddr,int *sockfd )
{
	(*sockfd) = socket(AF_INET,SOCK_STREAM,0);
	bzero(seraddr,sizeof(*seraddr));
	(*seraddr).sin_family = AF_INET;
	(*seraddr).sin_port = htons(8888);
	(*seraddr).sin_addr.s_addr = inet_addr("192.168.1.26");
	connect(*sockfd,(struct sockaddr*)seraddr,sizeof(*seraddr));
}
