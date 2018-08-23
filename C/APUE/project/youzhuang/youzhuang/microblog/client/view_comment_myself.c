#include"apue.h"
#include"microblog.h"

void view_comment_myself(SUer_basic_info *data,int sockfd)
{	
	int Ture;
	int i = 0;
	char blog[1024];

	write(sockfd,data->s_nick_name,strlen(data->s_nick_name)+1);
	read(sockfd,&Ture,sizeof(int));
	if(Ture != 0)
	{
		space();
		printf(" ** 系统出错 **\n");
		return ;
	}
	read(sockfd,&Ture,sizeof(int));
	read(sockfd,&Ture,sizeof(int));
	while(1)
	{
		bzero(blog,sizeof(blog));
		read(sockfd,&Ture,sizeof(int));
		if(Ture == 0)
		{
			if(i == 0)
			{
				space();
				printf("**您还没发表过微博,快去发表微博吧**\n");
				space();
				printf("**输入回车返回**");
				scanf("%[^\n]",blog);
				Ture = -1;
				write(sockfd,&Ture,sizeof(int));
				return;
			}
			break;
		}
		read(sockfd,blog,Ture);
		i++;
		read(sockfd,&Ture,sizeof(int));
	}
	comment(data,sockfd);
	Ture = -1;
	write(sockfd,&Ture,sizeof(int));
	return;
}
