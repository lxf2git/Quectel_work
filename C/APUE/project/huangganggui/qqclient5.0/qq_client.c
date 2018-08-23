#include "qqclient.h"
Thread_Data * pHead_list;
Thread_Data * pHead_send;
Thread_Data * pHead_recv;
Thread_Data * pHead_reply;
Thread_Data * pHead_file;
pthread_t send_id,recv_id;
extern pthread_t send_chooseid;
extern pthread_t recv_chooseid;
jmp_buf jmpbuffer;
sem_t s;

int main()
{
		atexit(my_exit);
		Socks Socks;
		int login_mode;	
		Socks.sockfd_send = initSockfd_Serive(&Socks.addr_send);//初始化目的端7563
		Socks.sockfd_recv = initSockfd_Client(&Socks.addr_recv);//初始化源端8888
		Socks.send_check = initSend_Check(&Socks.addr_Schec);   //发送检测端7777
		Socks.recv_check = initRecv_Check(&Socks.addr_Rchec);   //接受检测端6563
		chain_init(&pHead_list);	//初始化链表
		chain_init(&pHead_send);	//初始化链表
		chain_init(&pHead_recv);	//初始化链表
		chain_init(&pHead_reply);	//初始化链表
		chain_init(&pHead_file);	//初始化链表
		dir_init(MYDIR);     		//初始化目录
		sem_init(&s,0,1);	
		sigsetjmp(jmpbuffer,1);
		login_mode = login_menu(); 	//界面
		if(login_mode == 1)
		{
				sData_package  package_register;
//				package_register = register_fun(Socks.sockfd_send,&Socks.addr_send,Socks.sockfd_recv);//注册recv
				package_register = register_fun(Socks);//注册recv

		}

		sData_package  package_login;
//		package_login = login_fun(Socks.sockfd_send,&Socks.addr_send,Socks.sockfd_recv);           //登录
		package_login = login_fun(Socks);           //登录
		signal(SIGINT,my_leave);
		pthread_create(&recv_id,NULL,Recv_main,(void*)&Socks);
		pthread_create(&send_id,NULL,Send_main,(void*)&Socks);

		while(1);

}


int login_menu()
{
		int login_mode;
		do
		{
				printf("plese input "RED"0 To login "NONE"or"RED" 1 To register"NONE"\n");
				scanf("%d",&login_mode);
		}while((login_mode != 0)&&(login_mode != 1));
		return login_mode;

}


int Send_fun(const pData_package package,const struct sockaddr_in *paddr,int sockfd)
{
		printf("\n"GRE"______MODE:%d_________TIME:%s"NONE"\n",package->mode,package->time);
		printf("data:%s(mode:%d port:%d  toip:%s)\n",package->dorinform.data,package->mode,ntohs(paddr->sin_port),inet_ntoa(paddr->sin_addr));
		printf("destip:%s   srip:%s\n",package->destAddr,package->sourceAddr);
		printf("destuser:%s   srcuser:%s\n",package->dest_user,package->src_user);
		if( 			(package->mode != LOGIN)          && 
			 			(package->mode != REGISTER)
		  )		
		write_file(*package);
		
		sendto(sockfd,package,
						sizeof(sData_package),0,
						(struct sockaddr *)paddr,
						sizeof(struct sockaddr_in));

}
sData_package Recv_fun(struct sockaddr_in *paddr,int rockfd)
{
		sData_package package;
		bzero(&package,sizeof(package));
		socklen_t len = sizeof(struct sockaddr_in);
		recvfrom(rockfd,&package,
						sizeof(sData_package),0,
						(struct sockaddr *)paddr,&len);
		printf("\n"RED"_______MODE:%d_______TIME:%s"NONE"\n",package.mode,package.time);
		printf("destip:%s   srip:%s\n",package.destAddr,package.sourceAddr);
		printf("destuser:%s   srcuser:%s\n",package.dest_user,package.src_user);
		if( 			(package.mode != CHECK)          && 
						(package.mode != LOGINSUCCEED)   &&
						(package.mode != REGISTERERROR)  &&
						(package.mode != LOGINERROR)     &&
						(package.mode != REGISTERSUCCEED)  
          )
		write_file(package);
		return package;
}
void my_leave(int sig)
{
		printf("发送离开信息\n");
		Thread_Data *pTemp;
		Socks Socks;
		Socks.sockfd_send = initSockfd_Serive(&Socks.addr_send);//初始化目的端7563
		
		pTemp = send_leave(1,SERVICE_IP,"service");
		Send_fun(&(pTemp->data),&(Socks.addr_send),Socks.sockfd_send);
		printf("等待线程结束\n");
		
		pthread_cancel(send_chooseid);
		pthread_join(send_chooseid,NULL);
		pthread_cancel(recv_chooseid);
		pthread_join(recv_chooseid,NULL);
		pthread_cancel(send_id);
		pthread_join(send_id,NULL);
		pthread_cancel(recv_id);
		pthread_join(recv_id,NULL);
		
		my_free_chain(pHead_list);
		my_free_chain(pHead_send);
		my_free_chain(pHead_recv);
		printf("good day\n");
		_exit(0);
	

}
int write_file(sData_package package)
{
		int fd = open(package.dest_user,O_CREAT|O_APPEND|O_WRONLY,0666);
		if(fd == -1)
		{
				perror(package.dest_user);
				return -1;
		}
		char buf[1024];
		bzero(buf,sizeof(buf));
		sprintf(buf,"%s:(MODE%dTIME%s)::%s\n",package.dest_user,package.mode,package.time,package.dorinform.data);
		write(fd,buf,strlen(buf));
		close(fd);

}
void my_free_chain(Thread_Data *pHead)
{
		Thread_Data *pTemp = pHead;
		Thread_Data *pDel = pHead;
		while(pTemp != pHead)
		{

				pDel = pTemp;
				pTemp = pTemp->next;
				pDel->prev->next = pDel->next;
				pDel->next->prev = pDel->prev;
				write_file(pDel->data);
				pDel->next = pDel;
				pDel->prev = pDel;
				free(pDel);
				
		}
}
void my_exit()
{
	my_leave(SIGINT);

}
