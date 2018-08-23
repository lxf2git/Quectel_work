#include"apue.h"
#include"struct.h"
void fun_stop()
{
	printf("主进程暂停\n");
	sem.sem_op = -1;
	semop(semid,&sem,1);
	printf("主进程开始运行\n");
}
//void fun_kill()
//{
//	kill(getpgrp(),SIGFILL); 

//}
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		show_err("argument");
	}
	semid = semget((key_t)0x123,1,IPC_CREAT|0666);
	semctl(semid,0,SETVAL,0);
	sem.sem_num = 0;
	sem.sem_flg = 0;
	int p=0;
		if(!(p=fork()))
		{
			talking();
		}
		waitpid(-1,NULL,WNOHANG);



	//atexit(fun_kill);
	signal(SIGUSR1,fun_stop);
	bzero(puf,sizeof(puf));
	sockfd =  socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		show_err("socket");
	}
	bzero(&seraddr,sizeof(seraddr));
	seraddr.sin_family=AF_INET;
	seraddr.sin_port = htons(atoi(argv[2]));
	seraddr.sin_addr.s_addr = inet_addr(argv[1]);
	if(connect(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr))<0)
	{
		close(sockfd);
		show_err("connect");
	}
	else
		printf("链接成功！\n");
	//tcp 完成三次握手
	len = sizeof(struct sockaddr_in);
	
setjmp(FLAG);
	while(1)
	{
        printf("\n\n  ****************\n   &欢迎来到神域&\n  ****************\n   ^_^ ￥￥￥ ^_^\n");
        printf(" ………………………………………………\n  #1# 进入神域  \n  #2# 注册成为天使\n  #3# 离开神域\n\n");
        printf("  我要：");
	bzero(puf,sizeof(puf));
	scanf("%s",puf);

	if(puf[0]=='1')
	{	
		login();	
		while(1)
		{
                printf("#1# 显示修改个人信息\n #2# 好友列表\n #3# VIP\n #4# 进入聊天室 \n #5# 退出\n  ");

		int d=0;
		scanf("%d",&d);
			switch(d)	
			{	
				case 1:
					personal();
					break;
				case 2:
					while(1)
					{
					printf("     @_@\n^^^^^^^^^^^^^^^^^\n#1# 显示好友\n#2# 与好友聊天\n#3# 添加好友\n#4# 测除好友\n#5# 返回上一层\n");
						int m=0;
						scanf("%d",&m);
						switch(m)
						{
						case 1:
							showfriends();
							break;
						case 2:
							talk_friend();
							break;
						case 3:
							add_friend();
							break;
						case 4:
							delet_friend();
							break;
						case 5:
							break;
						default :
							printf("输入错误！\n");
							break;
						}
						if(m==5)
							break;
					}
					break;
				case 3:
	
					break;


				case 5:
				//CHQQ
					bzero(&message,sizeof(message));
					message.flag = CHQQ;
					write(sockfd,&message,sizeof(message));
					kill(p,SIGKILL);
					break;
				default :
					printf("输入错误！\n");
					break;
			}
			if(d==5)
				break;
		}
	}
		if(puf[0]=='2')
	{
		myapply();
	}

	if(puf[0]=='3')
	{
		kill(p,SIGKILL);
		exit (0);
	}
	
	}
	
}
