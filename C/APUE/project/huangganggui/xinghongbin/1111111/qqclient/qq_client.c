#include "qqclient.h"
Thread_Data * pHead_list;

int main()
{
		Socks Socks;
		int login_mode;	
		Socks.sockfd_send = initSockfd_Serive(&Socks.addr_send);//初始化目的端
		Socks.sockfd_recv = initSockfd_Client(&Socks.addr_recv);//初始化源端
		Socks.send_check = initSend_Check(&Socks.addr_Schec);   //发送检测端
		Socks.recv_check = initRecv_Check(&Socks.addr_Rchec);   //接受检测端
		chain_init(&pHead_list);               //初始化好友链表

		login_mode = login_menu(); 				//界面
		if(login_mode == 1)
		{
				sData_package  package_register;
				package_register = register_fun(Socks.sockfd_send,&Socks.addr_send,Socks.sockfd_recv);//注册
				char buf[1024];
				bzero(buf,sizeof(buf));
				sprintf(buf,"mkdir %s",package_register.dorinform.loginInformation.userId);
				system(buf);
		}

		sData_package  package_login;
		package_login = login_fun(Socks.sockfd_send,&Socks.addr_send,Socks.sockfd_recv);           //登录
		int ret = chdir(package_login.dorinform.loginInformation.userId);
		if(ret == -1)
		{
				perror("chdir");
				exit(-1);
		}
		if(fork() == 0)
		{
				Recv_main(Socks);
		}
		else
		{
				sleep(1);
				Send_main(Socks);
		}



}


int login_menu()
{
		int login_mode;
		do
		{
				printf("do you want "RED"login"NONE" syetem and "RED"register"NONE"ID\n");
				printf(GRE"plese input "RED"0 To login "NONE"or"RED" 1 To register"NONE"\n");
				scanf("%d",&login_mode);
		}while((login_mode != 0)&&(login_mode != 1));
		return login_mode;

}


int Send_fun(pData_package package,struct sockaddr_in *paddr,int sockfd)
{
		
		sendto(sockfd,package,
						sizeof(sData_package),0,
						(struct sockaddr *)paddr,
						sizeof(struct sockaddr_in));

}
sData_package Recv_fun(struct sockaddr_in *paddr,int rockfd)
{
		sData_package package;
		bzero(&package,sizeof(package));
		int len = sizeof(struct sockaddr_in);
		puts("********");
		recvfrom(rockfd,&package,
						sizeof(sData_package),0,
						(struct sockaddr *)paddr,&len);
		puts("^^^^^^^");
		return package;
}
