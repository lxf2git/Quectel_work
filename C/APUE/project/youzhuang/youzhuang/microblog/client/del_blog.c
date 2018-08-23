#include"apue.h"
#include"microblog.h"

void del_blog(SUer_basic_info *data,int sockfd)
{
	int num;
	int Ture;
	write(sockfd,data->s_user_name,sizeof(data->s_user_name));
	space();
	printf("* 您要删除第几条微博:");
	scanf("%d",&num);
	write(sockfd,&num,sizeof(int));
	read(sockfd,&Ture,sizeof(int));
	if(Ture == 0)
	{
		space();
		printf("* 删除成功\n");
	}
	else
	{
		space();
		printf("* 删除失败\n");
	}
	return ;
}
