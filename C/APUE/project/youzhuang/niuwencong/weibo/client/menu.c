#include"apue.h"
#include"microblog.h"

int Menu(SUer_basic_info *data,int sockfd,struct sockaddr_in *seraddr)
{	
	int option;
	char ch[20];
	while(1)
	{
		clean_upground();
		option = 100;
		Connect_Server(seraddr,&sockfd);	
		write(sockfd,&option,sizeof(int));
		own_zone(data,sockfd);
		printf("\n\n");
		close(sockfd);
		space();
		printf(" ________________________________ \n");
		space();
		printf("|                                |\n");
		space();
		printf("|     搜索用户       ** 1 **     |\n");
		space();
		printf("|     查看关注       ** 2 **     |\n");
		space();
		printf("|     查看粉丝       ** 3 **     |\n");
		space();
		printf("|     发表微博       ** 4 **     |\n");
		space();
		printf("|     删除微博       ** 5 **     |\n");
		space();
		printf("|     迷你游戏       ** 6 **     |\n");
		space();
		printf("|     修改密码       ** 7 **     |\n");
		space();
		printf("|     注销登录       ** 8 **     |\n");
		space();
		printf("|     退出微博       ** 9 **     |\n");
		space();
		printf("|________________________________|\n\n");
		clean_downground();
		space();
		scanf("%d",&option);
		getchar();

		switch(option)
		{
			case 1:
				option = SEARCH;
				Connect_Server(seraddr,&sockfd);
				write(sockfd,&option,sizeof(int));
				search_menu(data,sockfd);
				close(sockfd);
				sleep1();
				break;
			case 2:
				option = ATTENTION;
				Connect_Server(seraddr,&sockfd);
				write(sockfd,&option,sizeof(int));
				view_attention(data,sockfd);
				close(sockfd);
				sleep1();
				break;
			case 3:
				option = FANS;
				Connect_Server(seraddr,&sockfd);
				write(sockfd,&option,sizeof(int));
				view_fans(data,sockfd);
				close(sockfd);
				sleep1();
				break;

			case 4:
				option = PUBLISH;
				Connect_Server(seraddr,&sockfd);
				write(sockfd,&option,sizeof(int));
				publish_blog(data,sockfd);
				close(sockfd);
				sleep1();
				break;
			case 5:
				option = 7;
				Connect_Server(seraddr,&sockfd);
				write(sockfd,&option,sizeof(int));
				del_blog(data,sockfd);
				close(sockfd);
				sleep1();
				break;

			case 6:
				space();
				printf("**       尚未开发, 敬请期待    ** \n");
				space();
				printf("**       创意有限, 商机无限    ** \n");
				space();
				printf("**        出售本版块广告位     ** \n");
				space();
				printf("**  详情咨询www.uplooking.com  ** \n");
				space();
				printf("**         输入回车键退出      ** ");
				scanf("%[^\n]",ch);
				getchar();
				sleep1();
				break;
			case 7:
				option = 8;
				Connect_Server(seraddr,&sockfd);
				write(sockfd,&option,sizeof(int));
				change_passwd(data,sockfd);
				close(sockfd);
				sleep1();	
				break;
			case 8:
				space();
				printf("** 您已注销登录,返回登录界面 **\n");
				sleep1();
				return;
			case 9:
				space();
				printf("** 您已退出系统 **\n");
				sleep1();
				space();
				printf("** 退出成功\n");
				exit(0);
		}
	}
}		
