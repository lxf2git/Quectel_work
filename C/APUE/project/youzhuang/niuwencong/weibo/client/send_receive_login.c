#include"apue.h"
#include"microblog.h"
int send_receive_login(int *log_reg,int sockfd,SUer_basic_info *data)
{
	write(sockfd,log_reg,sizeof(int));
	write(sockfd,data,sizeof(*data));
	int judge;
	read(sockfd,&judge,sizeof(int));
	if(*log_reg == LOGIN)
	{
		if(judge == 0)
		{
			space();
			printf("登录成功...\n\n");
			return 0;
		}
		else
		{
			space();
			printf("用户名或密码错误\n\n");
			return -1;
		}
	}
	if(*log_reg == REGISTER)
	{
		if(judge == 0)
		{
			space();
			printf("注册成功\n\n");
			return 0;
		}
		else if(judge == -1)
		{
			space();
			printf("用户名已存在\n\n");
			return -1;
		}
		else
		{
			space();
			printf("昵称已存在\n\n");
			return -1;
		}
	}
}
