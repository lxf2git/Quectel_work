#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Attention(int confd,struct user_info *s_data, int num)
{
		int ret;
		char user_name[20];
		PUser_info s_node_data;
		PFriend s_node;
		ret = read(confd,user_name,20);//关注用户
		if(ret <0)
		{
				perror("attention read");
				return;
		}
		s_node_data = find_user_name(user_name);//获取用户信息
		s_node = s_data->s_fanc->next;//查看关注
		while(s_node!=s_data->s_fanc)
		{
				if(s_node_data->s_user_basic_info.s_id == s_node->s_id)
				{
						ret = 0;
						break;
				}
				s_node = s_node->next;

		}
		if(s_node == s_data->s_fanc)
		{
				ret = -1;
		}


		if(num==1)
		{
				if(ret==0)
				{
						write(confd,&ret,sizeof(int ));//已关注
						return;
				}
				else
				{
						ret=-1;
						add_friend(s_node_data,s_data);//添加关注多功能函数
						write(confd,&ret,sizeof(int ));//加关注成功
						return;
				}
		}	
		else if(num==2)
		{
				if(ret==0)
				{
						ret=-1;
						del_friend(s_node_data,s_data);//被关注用户粉丝id消除，关注个数减少
						write(confd,&ret,sizeof(int ));//取消关注成功
						return;
				}
				else
				{
						ret = 0;
						write(confd,&ret,sizeof(int ));//未关注
						return;	
				}
		}
		close(confd);
}
