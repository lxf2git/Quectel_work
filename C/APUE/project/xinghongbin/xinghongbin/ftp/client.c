#include "../../apue.h"
#define SERPORT 7563
#define CLIENT 8888
#define DATA 1024
#define SUCCEED 1
#define FAIL 0

typedef struct info
{
		char user[DATA];
		char passwd[DATA];
		char addr[DATA];
		char cmd[DATA];
		char data[DATA];
		int mode;
}sData;


int send_data(int sockfd,struct sockaddr_in saddr,int mode);
int read_data(int sockfd,struct sockaddr_in saddr,int mode);
int read_passwd(int sockfd);
int put_init(int sockfd,struct sockaddr_in saddr);
int my_strcmp(char *cmd);


int main(int argc, char **argv)
{
		int sockfd = socket(AF_INET,SOCK_STREAM,0);
		if(sockfd == -1)
		{
				perror("socket");
				exit(-1);
		}
		int rsockfd = socket(AF_INET,SOCK_STREAM,0);
		if(rsockfd == -1)
		{
				perror("rsocket c");
				exit(-1);
		}
		
		struct sockaddr_in saddr,raddr,caddr;
		bzero(&saddr,sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_port = htons(SERPORT);
		saddr.sin_addr.s_addr = inet_addr(argv[1]);

		bzero(&raddr,sizeof(raddr));
		raddr.sin_family = AF_INET;
		raddr.sin_port = htons(CLIENT);
		raddr.sin_addr.s_addr = htonl(INADDR_ANY);

		int len = sizeof(saddr);
		int ret = connect(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
		if(ret == -1)
		{
				perror("connect");
				exit(-1);
		}
		int i,readfd;
		for(i=0;i<3;i++)
		{
				send_data(sockfd,saddr,0);
				if(i==0)
				{

						ret = bind(rsockfd,(struct sockaddr *)&raddr,len);
						if(ret == -1)
						{
								perror("bind");
								exit(-1);
						}
						listen(rsockfd,10);
						readfd = accept(rsockfd,(struct sockaddr *)&caddr,&len);
						if(readfd == -1)
						{
								perror("accept");
								exit(-1);
						}
				}



				ret = read_data(readfd,raddr,0);
				if(ret == SUCCEED)
				{
						break;
				}
		}
		if(i != 3)
		{
				while(1)
				{
						send_data(sockfd,saddr,1);
						read_data(readfd,raddr,1);

				}
		}
		
				
	

}

int send_data(int sockfd,struct sockaddr_in saddr,int mode)
{
		struct sockaddr_in raddr;
		int len = sizeof(saddr);

		sData buf_data;
		if(mode == 0)
		{

				put_init(sockfd,saddr);	
				bzero(&buf_data,sizeof(buf_data));
				read(0,buf_data.user,DATA);
				printf("passwd:");
				fflush(NULL);
				read(0,buf_data.passwd,DATA);
				buf_data.mode = 1;
				getsockname(sockfd,(struct sockaddr *)&raddr,&len);
				strcpy(buf_data.addr , inet_ntoa(raddr.sin_addr) );

				write(sockfd,&buf_data,sizeof(buf_data));
		}
		else
		{
				bzero(&buf_data,sizeof(buf_data));
				printf("\nftp>");
				fflush(NULL);
				read(0,buf_data.data,DATA);
				write(sockfd,&buf_data,sizeof(buf_data));

		}
		/*
		int on = 1;
		int ret = setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(int));
		if(ret == -1)
		{
				perror("setsockopt");
				return -1;
		}
		close(sockfd);
		*/




}
int read_data(int sockfd,struct sockaddr_in saddr,int mode)
{
		sData buf_data;
		if(mode == 0)
		{
				struct sockaddr_in raddr;
				int ret = read_passwd(sockfd);
				if(ret == 1)
						return SUCCEED;
				else
						return FAIL;
		}
		else
		{
				bzero(&buf_data,sizeof(buf_data));
				int ret =read(sockfd,&buf_data,sizeof(buf_data));
				if(ret == -1)
				{
						perror("read_data");
						exit(-1);
				}

		}




}
int read_passwd(int sockfd)
{
		int ret;
		sData buf_data;
		bzero(&buf_data,sizeof(buf_data));

		ret = read(sockfd,&buf_data,sizeof(buf_data));
		if(ret == -1)
		{
				perror("read read_cmd");
				exit(-1);
		}
		if(my_strcmp(buf_data.cmd) == 1)
		{
				printf("go in succeed\n");
				return SUCCEED;
		}
		else
		{
				printf("passw error\n");
				return FAIL;
		}



}
int put_init(int sockfd,struct sockaddr_in saddr)
{
		struct sockaddr_in raddr;
		int len = sizeof(raddr);
		char hostName[1024];
		char serviceName[1024];
		bzero(&raddr,sizeof(raddr));
		getpeername(sockfd,(struct sockaddr *)&raddr,&len);
//		getnameinfo((struct sockaddr *)&saddr,sizeof(struct sockaddr_in),hostName,sizeof(hostName),serviceName,sizeof(serviceName),0);
		printf("Connected to %s (%s).\n",inet_ntoa(raddr.sin_addr),inet_ntoa(raddr.sin_addr) );//服务器名字（地址）
		printf("happy everyday\n");
		printf("Name  (%s:%s):",inet_ntoa(raddr.sin_addr),getpwuid(getuid())->pw_name);//主机名 当强用户
		fflush(NULL);

}
int my_strcmp(char *cmd)
{
		if(cmd[1]=='s')
				return 1;
		else
				return 0;
}
