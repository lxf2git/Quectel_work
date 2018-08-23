#include"apue.h"
/*
*/

void func(int sig)
{
	exit(0);
}


int main()
{
	char puf[5]={0};
	char order[10]={0};
	char way[100]={0};//服务器路径
	char myway[100]={0};//客户端路径
	char recv[2048]={0};

#if 0

#endif
		socklen_t len=sizeof(struct sockaddr_in);
		char hostaddr[20]={0};
	
		int i=0,hostport=0;
		struct sockaddr_in sndaddr,tmpaddr;
		socklen_t addr_len = sizeof(struct sockaddr_in);
		char buf[100]={0};
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd<0)
		{
			show_err("socket");
		}

		bzero(&sndaddr,sizeof(sndaddr));
		tmpaddr.sin_family=AF_INET;
				printf("请输入ip地址:");
				scanf("%s",hostaddr);
				getchar();
				printf("请输入端口地址:");
				scanf("%d",&hostport);
				getchar();
		tmpaddr.sin_port=htons(hostport);
		tmpaddr.sin_addr.s_addr=inet_addr(hostaddr); 

	do
	{
		message.cmd=LOGIN;
		if(puf[0]=='2')
		{
			printf("用户名或密码错误请重新输入\n");}
			printf("请输入用户名：\n");
			scanf("%s",message.user_info.ftp_usrname);	
			printf("请输入密码：\n");
			scanf("%s",message.user_info.ftp_passwd);//写入结构体用户信息

			sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));//传送结构体到服务器
			sleep(1);
			recvfrom(sockfd,puf,sizeof(puf),MSG_DONTWAIT,(struct sockaddr*)&tmpaddr,&len);
			printf("%s",puf);
	}while(puf[0]=='2');//接受 1 继续，收到 2 重新循环输入信息

	if(puf[0]=='1')
	printf("登入成功！\n");

	bzero(&message,sizeof(message));

	signal(SIGINT,func);
	while(1)
	{
		bzero(order,sizeof(order));
		bzero(&message,sizeof(message));
		bzero(way,sizeof(way));				
		bzero(recv,sizeof(recv));
		bzero(myway,sizeof(myway));
		printf("ftp>");
		scanf("%s",order);
		if(!strcmp("ls",order))//判断命令种类
		{
			message.cmd=LS;
			if(getchar()==' ')
			{
			scanf("%s",way);//输入路径
			strcpy(message.ftp_ls_path,way);
			sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));
			read(sockfd,recv,sizeof(recv));//等待接收返回的文件名
			puts(recv);
			printf("我读到了\n");
			}
			else
			{
			sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));
			read(sockfd,recv,sizeof(recv));//等待接收返回的文件名
			puts(recv);
			}
			
		}
	
		if(!strcmp("cd",order))
		{
		message.cmd=CD;
		scanf("%s",way);
		strcpy(message.ftp_cd_path,way);
		sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));

		}		

		if(!strcmp("mkdir",order))
		{
		message.cmd=MKDIR;
		scanf("%s",way);
		strcpy(message.ftp_mkdir_path,way);
		sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));

		}

		if(!strcmp("pwd",order))
		{
		message.cmd=PWD;
		sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));

		read(sockfd,recv,sizeof(recv));	
		puts(recv);
		}
		
		if(!strcmp("get",order))
		{
			message.cmd=GET;
			scanf("%s",way);
			strcpy(message.ftp_get_file,way);
			sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));

			scanf("%s",myway);//本地路径
			int fd=open(myway,O_WRONLY|O_CREAT,0666);
			usleep(5000);
			bzero(recv,sizeof(recv));	
			while(1)
			{
				if(recvfrom(sockfd,recv,sizeof(recv),MSG_DONTWAIT,NULL,NULL)>0)
				write(fd,recv,strlen(recv));
				else break;
				printf("处理中\n");
				bzero(recv,sizeof(recv));	
			}bzero(recv,sizeof(recv));
			printf("get out==\n");
			close(fd);
			printf("get close fd==\n");
		}

		if(!strcmp("put",order))
		{
			scanf("%s",myway);//本地路径
			int fd = open(myway,O_RDONLY);//打开本地文件
			message.cmd=PUT;
	
			scanf("%s",way);//目的路径
			strcpy(message.ftp_put_file,way);
			sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));

			usleep(500);//等一会儿那边准备好再传输
		
			bzero(recv,sizeof(recv));
			while(read(fd,recv,sizeof(recv))!=0)
			{
				sendto(sockfd,recv,strlen(recv)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));
				bzero(recv,sizeof(recv));
			}
			close(fd);
		}
	
		if(!strcmp("quit",order))
		{
		 message.cmd=QUIT;
                 sendto(sockfd,&message,sizeof(message)+1,0,(struct sockaddr*)&tmpaddr,sizeof(tmpaddr));
	
		 break;
		}

		kill(SIGINT,getpid());


	}
		close(sockfd);
return 0;
}

