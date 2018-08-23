#include"apue.h"
#include"microblog.h"


void attenorcancel(SUer_basic_info *data,int sockfd,int option)
{
	int Ture;
	write(sockfd,&option,sizeof(int));
	write(sockfd,data->s_user_name,sizeof(data->s_user_name));
	read(sockfd,&Ture,sizeof(int));

	if(option == 1)
	{

		space();
		if(Ture == -1)

			printf("成功关注该微博\n");

		else
			printf("您已关注该微博\n");
	}

	else
	{
		space();
		if(Ture == -1)
			printf("成功取消关注该微博\n");
		else
			printf("您尚未关注该微博\n");	
	}
	return ;
}
