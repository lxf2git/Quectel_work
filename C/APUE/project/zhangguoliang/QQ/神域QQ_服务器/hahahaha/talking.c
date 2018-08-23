#include"apue.h"
#include"struct.h"
void *func(void *p);

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
                                        //设置UDP链接完成
                                        //                                        
                                        //
		printf("UDP运行\n");
//BEFORE:
	while(1)
	{
		bzero(&sudp,sizeof(sudp));
		
		recvfrom(sockfdu,&sudp,sizeof(sudp),0,(struct sockaddr*)&conaddr,&len);
	//	bzero(tm,sizeof(tm));
	//	recvfrom(sockfdu,tm,sizeof(tm),0,(struct sockaddr*)&conaddr,&len);	
	//	printf("%s\n",tm);
	
		printf(" ////////////////////////\n");
		kill(getppid(),SIGUSR1);
		if(sudp.flag==KOFD)
		{
			printf(" %s同意你了你的好友请求！&_&\n",sudp.virtual_name);
			
		}
		if(sudp.flag==NKOFD)
		{
			printf(" %s拒绝了你的好友请求！『……………… 』\n",sudp.virtual_name);
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
	/*	if(sudp.flag==AEXIT)
		{
			printf("你被服务器强制下线！『 ……………… 』\n");
			bzero(&message,sizeof(message));
			message.flag = CHQQ;
			write(sockfd,&message,sizeof(message));
			longjmp(FLAG,0);
		}
		if(sudp.flag==S_TALK)
		{
			printf("%s 请求对话,是否开始对话 &_& \n#1# 是\n#2# 否\n",sudp.virtual_name);	
			bzero(puf,sizeof(puf));
			scanf("%s",puf);
			if(puf[0]=='1')
				{
				write(sockfd,puf,sizeof(puf));
				sleep(1);
				printf("可以开始对话，按“#”结束对话\n");
				goto MT;
				}
			if(puf[0]=='2')
				{
				write(sockfd,puf,sizeof(puf));			
				bzero(&sudp,sizeof(sudp));
				printf("你已拒绝对方请求  *_*\n");
				goto BEFORE;
				}
		}
		 if(sudp.flag==N_TALK)
		{	
			bzero(&sudp,sizeof(sudp));
			printf("对方拒绝了你的请求！* = *\n");
			goto BEFORE;
		}
		 if(sudp.flag==M_TALK)
		{
MT:
			pthread_create(&td,NULL,func,NULL);//创建接受的同步线程
			while(1)
			{			
			printf("我说：");
			scanf("%s\n",tm);
				if(tm[0]=='#');
					{
						strcpy(tm,"对方已经退出会话 *_*\n");		
						break;
					}
			sendto(sockfdu,tm,strlen(tm)+1,0,(struct sockaddr*)&sudp.conaddr,sizeof(sudp.conaddr));
			bzero(tm,sizeof(tm));	
			}
			
		}*/
		//	bzero(&sudp,sizeof(sudp));
			sem.sem_op=+1;
			semop(semid,&sem,1);
	}

exit (0);
}	
void *func(void *p)
{
	while(1)
	{
	if(recvfrom(sockfdu,tm,sizeof(tm),0,(struct sockaddr*)&sudp.conaddr,&len)>0)
		{
		printf("%s说：",sudp.virtual_name);
		printf("%s\n",tm);
		bzero(tm,sizeof(tm));  
		}
	}
}
