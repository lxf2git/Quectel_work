#include"main.h"

enum{RECV = 1, SEND, EXIT};
void menu(int sockfd);
void receive_information(int sockfd);
void send_information(int sockfd);
void reply_information(int sockfd, struct sockaddr_in dest_addr);
int socket_fun();

int main()
{
		int sockfd = socket_fun();
		while(1)
		{
				menu(sockfd);
		}
		return 0;
}

void menu(int sockfd)
{
		int ret;
		printf("1、接收短信\n");
		printf("2、发送短信\n");
		printf("3、退出\n");
		scanf("%d",&ret);
		getchar();
		switch(ret)
		{
				case RECV:
						receive_information(sockfd);
						break;
				case SEND:
						send_information(sockfd);
						break;
				case EXIT:
						close(sockfd);
						exit(0);
						break;
				default:
						printf("!\n");
		}
}

void receive_information(int sockfd)
{
		char ch;
		char buf[256];
		struct sockaddr_in src_addr;
		int len = sizeof(src_addr);
		int size = recvfrom(sockfd, buf, sizeof(buf), MSG_DONTWAIT, (struct sockaddr *)&src_addr, &len);
		if(size < 0)
		{
				printf("你是不是寂寞了?\n");
				return;
		}
		printf("ip:%s port:%d\n", inet_ntoa(src_addr.sin_addr), ntohs(src_addr.sin_port));
		printf("%s\n",buf);
		printf("是否回复(Y/N):\n");
		scanf("%c",&ch);
		getchar();
		if(ch=='y')
		{
				reply_information(sockfd,src_addr);
		}
}

void send_information(int sockfd)
{
		char ip[20],buf[256];
		int port;
		struct sockaddr_in dest_addr;
		printf("请输入IP 端口号\n");
		scanf("%s%d",ip,&port);
		dest_addr.sin_family = AF_INET;
		dest_addr.sin_port = htons(port);
		dest_addr.sin_addr.s_addr = inet_addr(ip);
		printf("请输入内容:\n");
		scanf("%s",buf);
		getchar();
		int size = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
		if(size < 0)
		{
				perror("sendto");
				close(sockfd);
				exit(-1);
		}
}
void reply_information(int sockfd, struct sockaddr_in dest_addr)
{
		char buf[256];
		printf("请输入内容:\n");
		scanf("%s",buf);
		getchar();
		int size = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
		if(size < 0)
		{
				perror("sendto");
				close(sockfd);
				exit(-1);
		}
}

int socket_fun()
{
		int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
		if(sockfd < 0 )
		{
				perror("socket");
				exit(-1);
		}
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(8888);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);

		int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
		if(ret < 0)
		{
				perror("bind");
				close(sockfd);
				exit(-1);
		}
		return sockfd;
}
