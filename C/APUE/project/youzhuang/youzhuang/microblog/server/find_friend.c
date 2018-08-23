#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Find_fanc(int confd)
{
		printf("查看fanc\n");
		struct user_info *s_data;
		char user_name[20];
		int ret;
		read(confd, user_name, 20);
		s_data = find_user_name(user_name);
		PUser_info friend_head,friend_node;	
		init_user_info(&friend_head);
		find_fanc(friend_head,s_data);//获取好友链表头节点
		friend_node = friend_head->next;
		while(friend_node!=friend_head)
		{
				write(confd,friend_node->s_user_basic_info.s_nick_name,20);
				friend_node = friend_node->next;
		}
		ret=0;
		write(confd,&ret,sizeof(int ));
		free(friend_head);
		close(confd);
}
void *Find_friend(int confd)
{
		printf("查看关注\n");
		struct user_info *s_data;
		char user_name[20];
		int ret;
		read(confd, user_name, 20);
		s_data = find_user_name(user_name);

		PUser_info friend_head,friend_node;	
		init_user_info(&friend_head);
		find_friend(friend_head,s_data);//获取好友链表头节点

		friend_node = friend_head->next;
		while(friend_node!=friend_head)
		{
				write(confd,friend_node->s_user_basic_info.s_nick_name,20);
				friend_node = friend_node->next;
		}
		ret=0;
		write(confd,&ret,sizeof(int ));
		free(friend_head);
		close(confd);
}
