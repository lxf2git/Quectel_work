#include"apue.h"
#define SEND 's'
#define READ 'r'
#define REPLY 'a'
#define QUIT 'q'
#define CAT 'c'
void myexit(int sockfd)
{
	int on = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
	puts("Welcome to use !");
}
int main()
{
	char ch;
	struct sockaddr_in selfaddr,conaddr;
	bzero(&selfaddr,sizeof(selfaddr));
	bzero(&conaddr,sizeof(conaddr));
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		show_err("socket_main");
	}
	selfaddr.sin_family = AF_INET;
	selfaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	selfaddr.sin_port = htons(8888);
	int ret = bind(sockfd,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
	if(ret<0)
	{
		show_err("bind_main");
	}

	while(1)
	{
		printf("|*****<s>***************send infomation******|\n");
		printf("|*****<r>***************read infomation******|\n");
		printf("|*****<a>**************reply infomation******|\n");
		printf("|*****<c>**************cat her/his IP********|\n");
		printf("|*****<q>***************quit*****************|\n");

		printf("please input your change:\n");
		scanf("%c",&ch);
		getchar();
		switch(ch)
		{
			case SEND :
					send_info(sockfd);
					break;
			case READ :
					conaddr = read_info(sockfd);
					break;
			case REPLY :
					reply_info(sockfd,&conaddr);
					break;
			case CAT :
		printf("her/his IP:%s\n",inet_ntoa(conaddr.sin_addr));
					break;
			case QUIT :
					myexit(sockfd);
					close(sockfd);
					exit(0);
			default :
					puts("Input error!");
					break;

		}
	}
	return 0;
}
