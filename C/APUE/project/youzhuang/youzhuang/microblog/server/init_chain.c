//#include"./init.h"
#include "./init.h"


void create_memory(void **p,int size)
{
	*p = malloc(size);
	if(NULL == *p)
	{
		perror("malloc");
	}
}

void free_memory(void **p)
{
	if(NULL != *p)
	{
		free(*p);
		*p = NULL;
	}
}

void init_user_info(PUser_info *pnode_usrinfo)
{
	create_memory((void **)pnode_usrinfo,sizeof(SUser_info));
	(*pnode_usrinfo)->friend_num = 0;
	(*pnode_usrinfo)->fanc_num = 0;

	//初始化struct friend的 好友/粉丝 变量pnode_friend,pnode_fri_fans
	PFriend pnode_friend;
	init_friend(&pnode_friend);
	(*pnode_usrinfo)->s_friend = pnode_friend;
	PFriend pnode_fri_fans;
	init_friend(&pnode_fri_fans);
	(*pnode_usrinfo)->s_fanc = pnode_fri_fans;


	//初始化struct microblog的 用户发布微薄 变量p_blog
	PMicroblog p_blog;
	init_microblog(&p_blog);
	(*pnode_usrinfo)->s_microblog = p_blog;

	(*pnode_usrinfo)->prev = (*pnode_usrinfo);
	(*pnode_usrinfo)->next = (*pnode_usrinfo);
//	printf("complete use_info!\n");
}

//初始化一个好友/粉丝用户
void init_friend(PFriend *p_friend)
{
	create_memory((void **)p_friend,sizeof(SFriend));
	(*p_friend)->s_id = 0;
	(*p_friend)->prev = (*p_friend);
	(*p_friend)->next = (*p_friend);
//	printf("complete friend!\n");
}

//	printf("complete user_basic_info!\n");

//初始化一条微薄信息
void init_microblog(PMicroblog *p_blog)
{
	create_memory((void **)p_blog,sizeof(SMicroblog));
	create_memory((void **)&((*p_blog)->s_text),sizeof(SIZE));
	(*p_blog)->s_praise = 0;
	//(*p_blog)->s_text = NULL;
	//初始化评论
	init_comment(&((*p_blog)->s_comment));

	(*p_blog)->prev = (*p_blog);
	(*p_blog)->next = (*p_blog);
//	printf("complete microblog!\n");
}

//初始化一条评论
void init_comment(PComment *p_comm)
{
	create_memory((void **)p_comm,sizeof(SComment));
	create_memory((void **)&((*p_comm)->s_text),sizeof(SIZE));	
	//(*p_comm)->s_text = NULL;
	bzero((*p_comm)->s_nick_name,20);
	(*p_comm)->prev = (*p_comm);
	(*p_comm)->next = (*p_comm);
//	printf("complete comment!\n");
}


/*
int add_node()
{
	
}
*/
