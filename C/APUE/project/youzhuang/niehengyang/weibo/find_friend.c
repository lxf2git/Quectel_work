#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Find_friend(int confd,struct user_info *s_data)
{
	int ret;
	PUser_info friend_head,friend_node;	
	init_user_info(&friend_head);
	init_user_info(&friend_node);
	find_friend(friend_head,s_data);//获取好友链表头节点
	friend_node = friend_head->next;
	while(friend_node!=friend_head)
	{
	write(confd,friend_node->s_user_basic_info.s_nick_name,20);
	friend_node = friend_node->next;
	}
	ret=0;
	write(confd,&ret,sizeof(int ));
}
