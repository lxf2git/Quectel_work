#include"../apue.h"
#include"../microblog.h"
#include"init.h"

struct user_info *find_user_name(char *s_user_name)
{
		printf("find_user_name\n");
		if( NULL == s_user_name )
		{
				return NULL;
		}
		struct user_info *p = puihead->next;
		while( p != puihead)
		{
				if( strcmp(p->s_user_basic_info.s_user_name, s_user_name) == 0)
				{
						return p;
				}
				p = p->next;
		}
		return NULL;
}

struct friend *find_id(struct friend *phead, int id)
{
		printf("find_id\n");
		struct friend *p = phead->next;
		while(p!=phead)
		{
				if(p->s_id == id)
				{
						return p;
				}
				p=p->next;
		}
		return NULL;
}

struct user_info *find_nick(char *nick_name) //查找链表昵称  pfhead：查找表的头
{
		printf("find_nick_name\n");
		if( NULL==nick_name )
		{
				return NULL;
		}
		struct user_info *p = puihead->next;
		while( p != puihead )
		{
				if( strcmp(p->s_user_basic_info.s_nick_name, nick_name) == 0)
				{
						return p;
				}
				p=p->next;
		}
		return NULL;
}


int find_fanc(struct user_info *pfhead, struct user_info *user)
{
		printf("find_fanc\n");
		if( NULL==pfhead || NULL==user )
		{
				return FAIL;
		}
		struct user_info *p = puihead->next;
		struct user_info *find_list;
		struct friend *up = user->s_fanc->next;
		while( p != puihead )
		{
				up = user->s_fanc->next;
				while( up != user->s_fanc )
				{
						if( p->s_user_basic_info.s_id == up->s_id )
						{
								init_user_info(&find_list);
								find_list->s_user_basic_info = p->s_user_basic_info;
								find_list->s_microblog = p->s_microblog;
								find_list->friend_num = p->friend_num;
								find_list->fanc_num = p->fanc_num;
								find_list->s_fanc = p->s_fanc;
								find_list->s_friend = p->s_friend;
								add_back_info(pfhead,find_list);
						}
						up = up->next;
				}
				p=p->next;
		}
}

int find_friend(struct user_info *pfhead, struct user_info *user)
{
		printf("find_friend\n");
		if( NULL==pfhead || NULL==user )
		{
				return FAIL;
		}
		struct user_info *p = puihead->next;
		struct user_info *find_list;
		struct friend *up = user->s_friend->next;
		while( p != puihead )
		{
				up = user->s_friend->next;
				while( up != user->s_friend )
				{
						if( p->s_user_basic_info.s_id == up->s_id )
						{
								init_user_info(&find_list);
								find_list->s_user_basic_info = p->s_user_basic_info;
								find_list->s_microblog = p->s_microblog;
								find_list->friend_num = p->friend_num;
								find_list->fanc_num = p->fanc_num;
								find_list->s_fanc = p->s_fanc;
								find_list->s_friend = p->s_friend;
								add_back_info(pfhead,find_list);
						}
						up = up->next;
				}
				p=p->next;
		}
		return SUC;
}


int add_friend(struct user_info *user,struct user_info *friend)
{
		printf("add_friend\n");
		printf("user:%s\n",user->s_user_basic_info.s_nick_name);
		printf("friend:%s\n",friend->s_user_basic_info.s_nick_name);
		struct friend *uf,*ff;
		init_friend(&uf);
		uf->s_id=friend->s_user_basic_info.s_id;
		printf("关注：%d\n",uf->s_id);
		init_friend(&ff);
		ff->s_id=user->s_user_basic_info.s_id;
		printf("被关注：%d\n",ff->s_id);
		add_back_friend(user->s_friend, uf);
		add_back_friend(friend->s_fanc, ff);
		user->friend_num++;
		friend->fanc_num++;
}
int del_friend(struct user_info *user, struct user_info *friend)
{
		printf("del_friend\n");
		printf("user:%s\n",user->s_user_basic_info.s_nick_name);
		printf("friend:%s\n",friend->s_user_basic_info.s_nick_name);
		struct friend *uf,*ff;
		uf = find_id(user->s_friend, friend->s_user_basic_info.s_id);
		ff = find_id(friend->s_fanc, user->s_user_basic_info.s_id);
		printf("取消关注：%d\n",uf->s_id);
		printf("被取消关注：%d\n",ff->s_id);
		del_friend_node(&uf);
		del_friend_node(&ff);
		user->friend_num--;
		friend->fanc_num--;
}

int del_friend_node(struct friend **p)
{
		printf("@@\n");
		(*p)->next->prev = (*p)->prev;
		(*p)->prev->next = (*p)->next;
		printf("@@\n");
		(*p)->next = NULL;
		(*p)->prev = NULL;
		free_memory((void**)p);
}
