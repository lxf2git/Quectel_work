#include"apue.h"
#include"microblog.h"



void comment(SUer_basic_info *data,int sockfd)
{
	char blog[1024];
	char buf_comment[1024];
	char comment_name[20];
	int option = 8;
	int i = 0;
	int num = 0;
	int Ture;
	write(sockfd,&option,sizeof(int));
	space();
	printf("* 输入你要查看第几条微博:");
	scanf("%d",&option);
	getchar();
	write(sockfd,&option,sizeof(int));

	read(sockfd,&num,sizeof(int));
	if(num == 0)
	{
		space();
		printf("* 无此微博 *\n\n");
	}
	else
	{



		sleep1();
		clean_upground();

		bzero(blog,sizeof(blog));
		read(sockfd,blog,num);
		space();
		printf("%s\n\n",blog);
		while(1)
		{   
			bzero(buf_comment,sizeof(buf_comment));
			read(sockfd,&num,sizeof(int));
			if(num == 0)
			{ 
				if(i == 0)
				{ 
					space();
					printf("* 尚无评论 *\n\n");
				}
				break;
			}
			read(sockfd,buf_comment,num);
			bzero(comment_name,sizeof(comment_name));
			read(sockfd,comment_name,sizeof(comment_name));
			i++;
			space();
			printf("* %d *   %s:   %s\n\n",i,comment_name,buf_comment);
		}   
		space();
		printf("* 评论微博   * 1 *\n");
		space();
		printf("* 转发微博   * 2 *\n");
		space();
		printf("* 点赞微博   * 3 *\n");
		space();
		printf("* 删除评论   * 4 *\n");
		space();
		printf("* 返回上层   * 5 *\n");
		clean_downground();
		space();
		scanf("%d",&option);
		getchar();
		switch(option)
		{    
			case 1:
				write(sockfd,&option,sizeof(int));
				bzero(buf_comment,sizeof(buf_comment));
				space();
				printf("输入评论:");
				scanf("%[^\n]",buf_comment);
				getchar();
				write(sockfd,data->s_nick_name,sizeof(data->s_nick_name));
				num = strlen(buf_comment)+1;
				write(sockfd,&num,sizeof(int));
				write(sockfd,buf_comment,num);
				read(sockfd,&Ture,sizeof(int));
				space();
				if(Ture == 0)
					printf("* 评论成功 *\n\n");
				else
					printf("* 评论失败 *\n\n");
				return ;
			case 2:
				write(sockfd,&option,sizeof(int));
				write(sockfd,data->s_user_name,sizeof(data->s_user_name));
				read(sockfd,&Ture,sizeof(int));
	
				printf("%d\n",Ture);
	
				space();
				if(Ture == 0)
					printf("* 转发成功 * \n\n");
				else
					printf("* 转发失败 * \n\n");
				return ;
			case 3:
				write(sockfd,&option,sizeof(int));
				read(sockfd,&Ture,sizeof(int));
	
	
				space();
				if( Ture == 0)
					printf("* 点赞成功 *\n\n");
				else
					printf("* 点赞失败 *\n\n");
				return;
			case 4:
				write(sockfd,&option,sizeof(int));
				write(sockfd,data->s_user_name,sizeof(data->s_user_name));
				space();
				printf("* 要删除第几条评论:");
				scanf("%d",&option);
				getchar();
				write(sockfd,&option,sizeof(int));
				read(sockfd,&Ture,sizeof(int));
				
				printf("%d\n",Ture);
				
				if(Ture == 0)
				{
					space();
					printf("* 删除成功 *\n\n");
				}
				else
				{
					space();
					printf("* 删除失败 *\n\n");
				}
				return;
			case 5:
			default:
				option = -1;	
				write(sockfd,&option,sizeof(int));
				return;


		}
	}
}
