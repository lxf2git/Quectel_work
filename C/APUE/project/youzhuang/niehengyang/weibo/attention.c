#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Attention(int confd,struct user_info *s_data, int num)
{
	int ret;
	PUser_basic_info data;
	PUser_info s_node_data;
	
	init_user_info(&s_node_data);
	data = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
	PFriend s_node;
	init_friend(&s_node);
	ret = read(confd,data->s_user_name,20);//关注用户
	
	if(ret <0)
	{
		perror("attention read");
		return;
	}
	s_node_data = find_user_name(data->s_user_name);//获取用户信息
	s_node = s_data->s_fanc->next;//查看关注
	while(1)
	{
		if(s_node_data->s_fanc->s_id==s_node->s_id)
		{
			ret = 0;
			break;
		}
			s_node = s_node->next;
		if(s_node==s_data->s_fanc)
		{
			ret=-1;
			break;
		}
		
	}
		

			if(num==ATTENTION)
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
			else if(num==CANCEL)
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
					 write(confd,&ret,sizeof(int ));//未关注
					return;	
				}
			}


}
