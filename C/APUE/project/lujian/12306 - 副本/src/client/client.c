#include"apue.h"
Scolo colo;
char tick[100] = "G0000G1111G2222G3333G4444G5555G6666G7777G8888";

void myexit(int fd)
{
		printf("%s欢迎使用*******12<360>*******\n%s",colo.gren,colo.end);
		close(fd);
		exit(0);
}
void *output(void *argv)
{
  //	printf("%sInput your choice:\n%s",colo.red,colo.end);
	     	while(1)
		  {
		printf("\r");
		printf("%sInput your choice: %s",colo.blue,colo.end);
		fflush(stdout);
		usleep(1000*500);
		printf("\r");
		printf("                   ");
		fflush(stdout);
		usleep(1000*500);
		}
}
int main(int argc,char **argv)
{
		if(argc!=2)
		{
				show_err("a.out err!");
		}
		//创建连接server
		strcpy(colo.end,"\033[0m");
		strcpy(colo.blue,"\033[34m");
		strcpy(colo.yell,"\033[33m");
		strcpy(colo.violet,"\033[35m");
		strcpy(colo.gren,"\033[36m");
		strcpy(colo.white,"\033[37m");
		strcpy(colo.red,"\033[31m");
		strcpy(colo.shine,"\032[5m");
		int sockfd = socket(AF_INET,SOCK_DGRAM,0);
		if(sockfd<0)
		{
				show_err("socket");
		}
		struct sockaddr_in seraddr;
		bzero(&seraddr,sizeof(seraddr));
		seraddr.sin_family = AF_INET;
		seraddr.sin_port = htons(6666);
		seraddr.sin_addr.s_addr = inet_addr(argv[1]);

		//定义客户端运用的结构体
		struct cli_pakg client;
		bzero(&client,sizeof(client));
		client.fd = sockfd;
		client.seraddr = seraddr;
		int choice,ret=0;
		pthread_t fd;
		while(1)
		{
				printf("%s|**<1>***********注册用户***********|\n%s",colo.blue,colo.end);
				if(client.cliTser.flag==LOG_SUC)
				{
						printf("%s|**<2>***********切换用户***********|\n%s",colo.yell,colo.end);
				}
				else
						printf("%s|**<2>***********登录用户***********|\n%s",colo.yell,colo.end);
				printf("%s|**<3>***********查询火车票*********|\n%s",colo.violet,colo.end);
				printf("%s|**<4>***********购买火车票*********|\n%s",colo.gren,colo.end);
				printf("%s|**<5>***********查询已购买火车票***|\n%s",colo.blue,colo.end);
				printf("%s|**<6>***********退票***************|\n%s",colo.gren,colo.end);
				printf("%s|**<7>***********改签***************|\n%s",colo.yell,colo.end);
			       	printf("%s|**<8>***********退出***************|\n%s",colo.red,colo.end);
				pthread_create(&fd,NULL,output,(void *)&ret);
					//puts("Input your choice:");
				scanf("%d",&choice);
				getchar();
			       	pthread_cancel(fd);
			       	pthread_join(fd,NULL);
				switch(choice)
				{
						case REG :
								reg_user(&client);
								break;
						case LOG :
								user_login(&client);
								break;
						case QUE :
								que_all(client,QUE);
								break;
						case  ORD:
								ret = que_all(client,QUE);
								if(ret==1)
								ord_tick(client,ORD);
								break;
						case QUE_ORD : 
								que_ord(client);
								break;
						case RET :
								ret = que_ord(client);
								//	printf("ret:%d\n",ret);
								if(ret==1)
								ret_tick(client,RET);
								break;
						case CHANGE :
								ret = que_ord(client);
								if(ret==1)
								ret = ret_tick(client,CHANGE);
								if(ret==1)
								{
										que_all(client,CHANGE);
										ord_tick(client,CHANGE);
								}
								break;
						case QUIT :
								myexit(sockfd);
								break;
						default :
								puts("Input err!");
								break;
				}
		}
		return 0;
}
