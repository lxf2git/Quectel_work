#include"apue.h"
#include"microblog.h"



void own_zone(SUer_basic_info *data,int sockfd)
{
	char nick_name[20];
	char buf[1024];
	int size;
	int prasic;
	int i = 0;
	write(sockfd,data->s_user_name,sizeof(data->s_user_name));
	bzero(nick_name,sizeof(nick_name));
	read(sockfd,nick_name,sizeof(nick_name));
	strcpy(data->s_nick_name,nick_name);
	space();
	printf("    我的微博      *(%s)*\n\n\n",nick_name);
	while(1)
	{
		read(sockfd,&size,sizeof(int));
		if(size == 0)
		{
			if( i == 0)
			{
				space();
				printf("    您还什么都没有留下\n\n");
			}
			break;
		}
		i++;
		read(sockfd,buf,size);
		read(sockfd,&prasic,sizeof(int));
		space();
		printf("No.%d  %s  赞:%d人\n",i,buf,prasic);
	}
}
