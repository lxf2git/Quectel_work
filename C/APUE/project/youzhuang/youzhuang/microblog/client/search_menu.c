#include"apue.h"
#include"microblog.h"


void search_menu(SUer_basic_info *data,int sockfd)
{
	char blog[1024];
	char nick_name[20];
	int Ture;     //判断返回结果
	int i = 0;    //判断返回次数
	int attnum;   //关注个数
	int fans;     //粉丝个数
	int option;   //选项
	int praise;   //赞的个数
	int num = 0;  //返回字节数

	space();
	printf("搜索:");
	bzero(nick_name,sizeof(nick_name));
	scanf("%s",nick_name);
	getchar();
	write(sockfd,nick_name,strlen(nick_name)+1);

	read(sockfd,&Ture,sizeof(int));
	if(Ture != 0)
	{
		space();
		printf("** 无此用户 **\n");
		return ;
	}
	space();
	printf("** 正在跳转到%s的微博 **\n",nick_name);
	sleep1();

	while(1)
	{
		i = 0;
		read(sockfd,&attnum,sizeof(int));
		read(sockfd,&fans,sizeof(int));
		clean_upground();
		space();
		printf(" -> %s的微博\n\n",nick_name);
		space();
		printf(" ________________________________ \n");
		space();
		printf("|                                |\n");
		space();
		printf("|   关注:%4d人,   粉丝:%4d人   |    \n",attnum,fans);
		space();
		printf("|________________________________|\n\n");
		while(1)
		{
			bzero(blog,sizeof(blog));
			read(sockfd,&num,sizeof(int));
			if(num == 0)
			{
				if(i == 0)
				{
					space();
					printf("** 主人很懒,什么也没留下 **\n\n");
				}
				space();
				printf("\n\n");
				break;
			}
			read(sockfd,blog,num);
			i++;
			read(sockfd,&praise,sizeof(int));
			space();
			printf("No.%d  %s  赞:%d人\n\n",i,blog,praise);
		}
		space();
		printf(" ________________________________ \n");
		space();
		printf("|                                |\n");
		space();
		printf("|      关注微博      ** 1 **     |\n");
		space();
		printf("|      取消关注      ** 2 **     |\n");
		space();
		printf("|      查看微博      ** 3 **     |\n");
		space();
		printf("|      返回主页      ** 4 **     |\n");
		space();
		printf("|________________________________|\n");
		clean_downground();
		space();
		scanf("%d",&option);
		getchar();
		switch(option)
		{
			case 1:
			case 2:
				attenorcancel(data,sockfd,option);
				sleep1();
				break;
			case 3:
				comment(data,sockfd);
				sleep1();
				break;
			case 4:
			default:
				option = -1;
				write(sockfd,&option,sizeof(option));
				space();
				printf("正在返回主页\n");
				return ;
		}
	}
}

