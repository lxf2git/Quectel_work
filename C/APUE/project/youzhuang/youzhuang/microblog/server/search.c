#include "../apue.h"
#include "init.h"
#include "../microblog.h"


void *Search(int confd)
{
		printf("查找\n");
		int len=0, i, ret, num;
		char *user_name[20];
		PUser_basic_info data;
		data = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
		PUser_info s_data = NULL;
		PMicroblog s_node;
		ret = read(confd,data->s_nick_name,20);
		if(ret<0)
		{
				perror("search_read");
		}
		s_data = find_nick(data->s_nick_name);//获取用户名
		if(s_data==NULL)
		{
				ret = -1;
				write(confd, &ret, sizeof(ret));
				free_memory((void**)&data);
				close(confd);
				return ;
		}
		ret = 0;
		write(confd, &ret, sizeof(ret));

		while(1)
		{
				write(confd,&s_data->friend_num,sizeof(int ));//发送好友个数
				write(confd,&s_data->fanc_num,sizeof(int ));//发送粉丝个数
				s_node = s_data->s_microblog->next;
				while(s_node!=s_data->s_microblog)
				{
						int len;
						len = strlen(s_node->s_text)+1;
						write(confd,&len,sizeof(int));//发送赞
						int x = write(confd,s_node->s_text,len);//发送微博内容
						write(confd,&s_node->s_praise,sizeof(int));//发送赞
						s_node = s_node->next;
				}
				ret = 0;
				int blognum;

				write(confd,&ret,sizeof(ret));//微博发送完毕

				read(confd,&num,sizeof(int ));
				switch(num)
				{
						case 1:
								printf("关注\n");
								Attention(confd,s_data, num);
								break;
						case 2:
								printf("取消关注\n");
								Attention(confd,s_data, num);
								break;
						case 8:
								printf("查看微博评论!\n");
								read(confd,&blognum,sizeof(int ));
								s_node = s_data->s_microblog->next;
								for(i=1;i<blognum && s_node!=s_data->s_microblog;i++)
								{
										s_node = s_node->next;
								}
								if(s_node!=s_data->s_microblog)
								{
										len = strlen(s_node->s_text)+1;
										write(confd, &len, sizeof(int));
										write(confd, s_node->s_text,len);
										Comment_micorblog(confd,s_node->s_comment,s_data,s_node);//发表评论
								}
								else
								{
										write(confd, &len, sizeof(int));
								}
								break;
						case -1:
								printf("退出!\n");
								close(confd);
								free_memory((void**)&data);
								return;
								break;
				}
		}
		return SUC;

}
