#include"apue.h"
#define CONT 'y'
#define STOP 'n'
#define AGAIN 2
#define NO_AGAIN 3
#define state(flag) flag>1?AGAIN:NO_AGAIN
int send_info(int sockfd)
{
	int flag = 0;
	char ch;
	char ip_char[20];
	bzero(ip_char,sizeof(ip_char));
	printf("Input the ip to send:\n");
	scanf("%s",ip_char);
	char str[1024];

	struct sockaddr_in conaddr;
	bzero(&conaddr,sizeof(conaddr));

	if(sockfd<0)
	{
		show_err("socket_send_err");
	}
	conaddr.sin_family = AF_INET;
	conaddr.sin_port = htons(8888);
	conaddr.sin_addr.s_addr = inet_addr(ip_char);
	while(1)
	{
		flag++;
		if(state(flag)==AGAIN)
		{
			puts("是否继续给此IP发消息(同意'y',反对'n')");
			getchar();
			scanf("%c",&ch);
	
			if(ch == STOP)
			{
				break;
			}
			if(ch!=STOP&&ch!=CONT)
			{
				puts("Input error,please input again:");
				continue;
			}
		}
		bzero(str,sizeof(str));
		puts("Input the str to send:");
		getchar();
		scanf("%[^\n]",str);

		if(sendto(sockfd,str,strlen(str)+1,0,
			(struct sockaddr *)&conaddr,sizeof(conaddr))<0)
		{
			close(sockfd);
			puts("sendto error");
			getchar();
			return FAIL;
		}
	}
	getchar();
	return SUC;
}
int reply_info(int sockfd,struct sockaddr_in *conaddr)
{
	int flag = 0;
	char ch;

	in_addr_t ip;
	if(conaddr->sin_addr.s_addr==INADDR_ANY)
	{
		puts("No body to reply!");
		send_info(sockfd);
	}
	else
	{
		char str[1024];
		while(1)
		{
			flag++;
			if(state(flag)==AGAIN)
			{
				puts("是否继续回复此IP(同意'y',反对'n')");
				getchar();
				scanf("%c",&ch);

				if(ch == STOP)
				{
					bzero(conaddr,sizeof(*conaddr));
					break;
				}
				if(ch!=STOP&&ch!=CONT)
				{
				puts("Input error,please input again:");
					continue;
				}
				getchar();
			}
			bzero(str,sizeof(str));
			puts("Input the str to send:");
			scanf("%[^\n]",str);

			if(sendto(sockfd,str,strlen(str),0,
			(struct sockaddr *)conaddr,sizeof(*conaddr))<0)
			{
				close(sockfd);
				puts("sendto error");
				getchar();
				return FAIL;
			}
		}
		getchar();
	}
	return SUC;
}
