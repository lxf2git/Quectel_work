
#include "qqclient.h"
extern jmp_buf jmpbuffer;
extern jmp_buf jmp_choose;
sData_package login_fun(Socks Socks)
{
 Sendinit[LOGIN] = init_login;
		struct sockaddr_in raddr;
		sData_package login_package,recv_package;
		do{
				printf("正在登录..............login\n");
				my_jmpMenu(1);
				bzero(&login_package,sizeof(login_package));
				login_package = init_login(NULL,NULL);
				///////////////////////////////////////////
				SendToService(Socks,login_package);
					
				bzero(&raddr,sizeof(struct sockaddr_in));
				bzero(&recv_package,sizeof(login_package));
				recv_package = Recv_fun(&raddr,Socks.sockfd_recv);
		}while((recv_package.mode != LOGINSUCCEED) && (printf(RED"%s"NONE"\n",recv_package.dorinform.data)));
		dir_init(login_package.dorinform.loginInformation.userId);
		printf(GRE"%s"NONE"\n",recv_package.dorinform.data);
		return recv_package;
}
sData_package register_fun(Socks Socks)
{
 Sendinit[REGISTER] = init_register;
		struct sockaddr_in raddr;
		sData_package login_package,recv_package;
		do
		{

				printf("正在注册..........regist\n");
				my_jmpMenu(1);
				bzero(&login_package,sizeof(sData_package));
				login_package = init_register(NULL,NULL);	
				SendToService(Socks,login_package);
				bzero(&raddr,sizeof(struct sockaddr_in));
				bzero(&recv_package,sizeof(login_package));
				recv_package = Recv_fun(&raddr,Socks.sockfd_recv);
				printf("%d\n",recv_package.mode);
		}while((recv_package.mode == REGISTERERROR) && printf(RED"error:%s"NONE"\n",recv_package.dorinform.data));
		printf(GRE"%s"NONE"\n",recv_package.dorinform.data);
		return recv_package;
}
/*
void my_login(int sig)
{
		printf("data 重发\n");
		siglongjmp(jmp_login,1);
}
*/
void my_jmpMenu(int sig)
{
		printf("按s继续按q取消\n");
		
		int ch;
		while( (ch = getchar()) == '\n'|| ch == ' ');
		ungetc(ch,stdin);
		if(ch == 'q')
		{
				getchar();
				if(sig == 1)
				siglongjmp(jmpbuffer,1);
				if(sig == 2)
				siglongjmp(jmp_choose,1);

		}
				getchar();

}
