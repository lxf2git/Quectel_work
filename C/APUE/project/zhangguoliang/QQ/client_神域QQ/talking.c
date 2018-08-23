#include"apue.h"
#include"struct.h"
void *func(void *p);
struct to_udp sudp;
void talking()
{
	
	pthread_t td;
	semid = semget((key_t)0x123,1,IPC_CREAT|0666);
	sem.sem_num = 0;
 	sem.sem_flg = 0;


        sockfdu = socket(AF_INET,SOCK_DGRAM,0);
        if(sockfdu<0)
        {
                show_err("socketudp");
        }       
        bzero(&selfaddr,sizeof(selfaddr));
        selfaddr.sin_family=AF_INET;
        selfaddr.sin_port=htons(8888);
        selfaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        
        ret=bind(sockfdu,(struct sockaddr*)&selfaddr,sizeof(selfaddr));
        if(ret<0)
        {
                close(sockfdu);
                show_err("bind");
        }       
BEFORE:
	while(1)
	{
		bzero(&sudp,sizeof(sudp));
		
		recvfrom(sockfdu,&sudp,sizeof(sudp),0,(struct sockaddr*)&conaddr,&len);
		kill(getppid(),SIGUSR1);
		printf(" /////////////////////////////////////////////\n");
		if(sudp.flag==KOFD)
		{
			printf(" %s同意你了你的好友请求！&_&\n",sudp.virtual_name);
			sem.sem_op=+1;
			semop(semid,&sem,1);
			
		}
		if(sudp.flag==NKOFD)
		{
			printf(" %s拒绝了你的好友请求！『……………… 』\n",sudp.virtual_name);
			sem.sem_op=+1;
			semop(semid,&sem,1);
		}
		if(sudp.flag==OKFD)
		{
			printf(" 天使￥%s￥请求加您好友是否同意：\n",sudp.virtual_name);
			conaddr.sin_family=AF_INET;
			conaddr.sin_port=htons(8888);
			conaddr.sin_addr.s_addr=inet_addr("192.168.1.16");
			printf("#1# 是\n#0# 否\n");
			bzero(puf,sizeof(puf));
			scanf("%s",puf);
			printf("输入%s\n",puf);
			sendto(sockfdu,puf,2,0,(struct sockaddr*)&conaddr,sizeof(conaddr));

		}
		if(sudp.flag==AEXIT)
		{
			printf("你被服务器强制下线！『 ……………… 』\n");
			sem.sem_op=+1;
			semop(semid,&sem,1);
			longjmp(FLAG,0);
		}
		if(sudp.flag==RFILE)
		{
			printf("天使%s请求向你传送文件，是否接受：\n#1# 是\n#2#否\n ",sudp.virtual_name);
			conaddr.sin_family=AF_INET;
			conaddr.sin_port=htons(8888);
			conaddr.sin_addr.s_addr=inet_addr("192.168.1.16");
			scanf("%s",puf);
			while(1)
			{
				if(puf[0]=='1')	
				{
					sendto(sockfdu,puf,2,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
					break;
				}
				else if(puf[0]=='2')
				{	
					sendto(sockfdu,puf,2,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
					break;
				}
			else
				{printf("输入错误！\n");}
			}
			sleep(1);
		}
		if(sudp.flag==NFILE)
		{
			printf("%s拒绝了你传送文件的请求！\n",sudp.virtual_name);
		}
		if(sudp.flag==YFILE)
		{
			printf("%s同意接受文件！\n",sudp.virtual_name);
			while(1)
				{
				printf("输入要传送的文件路径：");
				scanf("%s",myway);
				fd = open(myway,O_RDONLY);//打开本地路径
				if(fd<0)
					{printf("打开文件失败！\n");}
				else
					{break;}
				}
			sudp.flag=READF;
			printf("为传送文件命名：");
			scanf("%s",sudp.file_name);
			sendto(sockfdu,&sudp,sizeof(sudp),0,(struct sockaddr*)&sudp.conaddr,sizeof(sudp.conaddr));
			printf("开始传输！\n");
			while(read(fd,tm,sizeof(tm))!=0)
			{
				sendto(sockfdu,tm,strlen(tm),0,(struct sockaddr*)&sudp.conaddr,sizeof(sudp.conaddr));
				bzero(tm,sizeof(tm));	
			}
			sleep(1);
			printf("传输结束！\n");
			close(fd);
			sudp.flag=100;
		}
		if(sudp.flag==READF)
		{
			printf("开始下载文件: %s \n",sudp.file_name);
			printf("默认存储在当前路径下\n");
			ft = open(sudp.file_name,O_RDWR|O_CREAT,0666);
			usleep(5000);
			bzero(tm,sizeof(tm));
			while(recvfrom(sockfdu,tm,sizeof(tm),MSG_DONTWAIT,NULL,NULL)>0)
			{
				write(ft,tm,strlen(tm));
				bzero(tm,sizeof(tm));	
			}
			printf("文件下载结束\n");
			close(ft);
		}
		if(sudp.flag==SCFILE)
		{
			printf("服务器可以上传文件！\n");
			while(1)
				{
				printf("输入要上传的文件路径：");
				scanf("%s",myway);
				fd = open(myway,O_RDONLY);//打开本地路径
				if(fd<0)
					{printf("打开文件失败！\n");}
				else
					{break;}
				}

			sudp.flag=READF;//服务器收到 READF 开始接受离线文件
			conaddr.sin_family=AF_INET;
			conaddr.sin_port=htons(8888);
			conaddr.sin_addr.s_addr=inet_addr("192.168.1.16");
			printf("为上传文件命名：");
			scanf("%s",sudp.file_name);
			sendto(sockfdu,&sudp,sizeof(sudp),0,(struct sockaddr*)&conaddr,sizeof(sudp.conaddr));
			printf("开始上传！\n");
			while(read(fd,tm,sizeof(tm))!=0)
			{
				sendto(sockfdu,tm,sizeof(tm),0,(struct sockaddr*)&conaddr,sizeof(sudp.conaddr));
				bzero(tm,sizeof(tm));	
			}
			sleep(1);
			close(fd);
			printf("上传结束！\n");
		}
		//	printf("%d\n",XZTALK);
		 if(sudp.flag==XZFILE)
		{
			sleep(1);
			printf("开始从服务器下载%s的离线文件 %s\n",sudp.virtual_name,sudp.file_name);
			printf("默认存储在当前路径下\n");
			ft = open(sudp.file_name,O_RDWR|O_CREAT,0666);
			while(recvfrom(sockfdu,tm,sizeof(tm),MSG_DONTWAIT,NULL,NULL)>0)
			{
				write(ft,tm,strlen(tm));
				bzero(tm,strlen(tm));	
			}
			printf("文件下载结束\n");		
			close(ft);
		//	pause();
			sudp.flag=101;
		}
		if(sudp.flag==SCTALK)
		{
			printf("您已可以向对方发送离线消息，请保持在250字内，按#键结束输入￥_￥\n");
			conaddr.sin_family=AF_INET;
			conaddr.sin_port=htons(8888);
			conaddr.sin_addr.s_addr=inet_addr("192.168.1.16");
			scanf("%[^#]",tm);
			getchar();
			sendto(sockfdu,tm,strlen(tm)+1,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
			printf("\n");
			printf("服务器将为你的消息保存3天\n");
		}
		if(sudp.flag==XZTALK)
		{
			printf("天使%s在您离开神域期间对你说：\n",sudp.virtual_name);
			recvfrom(sockfdu,tm,sizeof(tm),0,NULL,NULL);
			printf("%s",tm);
			printf("\n以上\n");
		}
		if(sudp.flag==S_TALK)
		{
			printf("%s 请求对话,是否开始对话 &_& \n#1# 是\n#2# 否\n",sudp.virtual_name);	
			bzero(puf,sizeof(puf));
			scanf("%s",puf);
			conaddr.sin_family=AF_INET;
			conaddr.sin_port=htons(8888);
			conaddr.sin_addr.s_addr=inet_addr("192.168.1.16");
			if(puf[0]=='1')
				{
				sendto(sockfdu,puf,2,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
				sleep(1);
				printf("可以开始对话，按“#”结束对话\n");
				goto MT;
				}
			if(puf[0]=='2')
				{
				sendto(sockfdu,puf,2,0,(struct sockaddr*)&conaddr,sizeof(conaddr));
				bzero(&sudp,sizeof(sudp));
				printf("你已拒绝对方请求  *_*\n");
				sem.sem_op=+1;
				semop(semid,&sem,1);
				goto BEFORE;
				}
		}
		 if(sudp.flag==N_TALK)
		{	
			bzero(&sudp,sizeof(sudp));
			printf("对方拒绝了你的请求！* = *\n");
			sem.sem_op=+1;
			semop(semid,&sem,1);
			goto BEFORE;
		}
		 if(sudp.flag==M_TALK)
		{
MT:
			pthread_create(&td,NULL,func,NULL);//创建接受的同步线程
			//printf("准备聊天地址:%s\n",inet_ntoa(sudp.conaddr.sin_addr));
			//sudp.conaddr.sin_family=AF_INET;
			//sudp.conaddr.sin_port=htons(8888);
			while(1)
			{			
				scanf("%s",tm);
				if(tm[0]=='#')
				{
					strcpy(tm,"我已经退出会话 *_*\n");		
					sendto(sockfdu,tm,strlen(tm)+1,0,(struct sockaddr*)&sudp.conaddr,sizeof(sudp.conaddr));
					break;
				}
				sendto(sockfdu,tm,strlen(tm)+1,0,(struct sockaddr*)&sudp.conaddr,sizeof(sudp.conaddr));
				bzero(tm,sizeof(tm));	
			}
			//printf("我出while了\n");
			
		}
			sem.sem_op=+1;
			semop(semid,&sem,1);
			printf("|||||||||||||||||||||||||||||||||||||||||||||||\n");
	}

exit (0);
}	
void *func(void *p)
{
	//printf("我进线程了\n");
	while(1)
	{
		recvfrom(sockfdu,tm,sizeof(tm),0,(struct sockaddr*)&sudp.conaddr,&len);
		printf("%s说：",sudp.virtual_name);
		printf("%s\n",tm);
		bzero(tm,sizeof(tm));  
		
	}
}
