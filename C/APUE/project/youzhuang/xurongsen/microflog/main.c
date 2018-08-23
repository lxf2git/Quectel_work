
#include"init.h"



int main()
{
//&&&&&&&&&&&添加链表测试——————————————————————————
	int ret;
	init_user_info(&phead_use_info);
	PUser_info puser_info;
	init_user_info(&puser_info);
	puser_info->fanc_num = 99;


	ret = add(USER_INFO,(void **)&phead_use_info,(void **)&puser_info ,add_back_info);
	if(ret == FAILED)
	{
		printf("use_info 添加失败\n");
	}
	
#if 0
	//在头节点的下一个用户的下的添加microblog节点
	PUser_info p_info;
	p_info = phead_use_info->next->next;

	PMicroblog p_blog,p_blg2;
	init_microblog(&p_blog);
	init_microblog(&p_blg2);
	p_blog->s_praise = 520;
	p_blg2->s_praise = 340;
	strcpy(p_blog->s_text, "hello world!\n");
	printf("user_basic_info before!\n");
	printf("p_blog->%d\n",p_blog->s_praise);
	ret = add(BLOG,(void **)&(p_info->next->s_microblog),
					(void **)&p_blog,add_back_blog);
	if(ret == FAILED)
	{
		printf("comment 添加失败\n");
	}
	ret = add(BLOG,(void **)&(p_info->next->s_microblog),
					(void **)&p_blg2,add_back_blog);
	if(ret == FAILED)
	{
		printf("comment 添加失败\n");
	}
	printf("init_comm after!\n");
	printf("init_blog_addr:%d\n",phead_use_info->fanc_num);//->s_praise);
	printf("init_blog_addr:%d\n",phead_use_info->next->fanc_num);//->s_praise);
	printf("init_blog_head:%d\n",phead_use_info->next->s_microblog->s_praise);
	//第一个节点
	printf("init_blog_fir:%d\n",phead_use_info->next->s_microblog->next->s_praise);
	printf("init_blog_fir:%d\n",p_info->next->s_microblog->next->s_praise);
	printf("init_blog_friaddr:%p\n",phead_use_info->next->s_microblog->next->s_praise);
	printf("init_blog_firaddr:%p\n",p_info->next->s_microblog->next->s_praise);
	printf("init_blog_firaddr:%s",p_info->next->s_microblog->next->s_text);
//	search((void **)&(p_info->next->s_microblog));//测试
#endif

#if 0
//-----------在上面的基础上的microblog下添加一个评论链表comment
	printf("init_comm before!\n");
	PComment pcomm;
	init_comment(&pcomm);
	strcpy(pcomm->s_user_name,"haha");

	ret = add(COMM,(void **)&(p_info->next->s_microblog->next->s_comment),
					(void **)&pcomm,add_back_comm);
	if(ret == FAILED)
	{
		printf("comment 添加失败\n");
	}
	printf("init_comm after!\n");
	printf("init_head:%s\n",phead_use_info->next->s_microblog->next->s_comment->s_user_name);
	printf("init_fir:%s\n",phead_use_info->next->s_microblog->next->s_comment->next->s_user_name);
#endif

#if 0
	PFriend p_friend;
	init_friend(&p_friend);
	p_friend->s_id = 122;
	ret = add(FRIEND,(void **)&(p_info->next->s_friend),
					(void **)&p_friend,add_back_friend);
	if(ret == FAILED)
	{
		printf("comment 添加失败\n");
	}
	printf("init_friend_fir:%d\n",phead_use_info->next->s_friend->next->s_id);
	printf("init_friend_fir:%p\n",p_info->next->s_friend->next->s_id);
#endif
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

#if 0
	PFriend p_fri_fans;
	init_friend(&p_fri_fans);
	p_fri_fans->s_id = 56789;
	ret = add(FRI_FANS,(void **)&(p_info->next->s_fanc),
					(void **)&p_fri_fans,add_back_friend);
	if(ret == FAILED)
	{
		printf("comment 添加失败\n");
	}
	PFriend p_fri_fans2;
	init_friend(&p_fri_fans2);
	p_fri_fans2->s_id = 9999;
	ret = add(FRI_FANS,(void **)&(p_info->next->s_fanc),
					(void **)&p_fri_fans2,add_back_friend);
	if(ret == FAILED)
	{
		printf("comment 添加失败\n");
	}
	printf("init_friend_fir:%d\n",phead_use_info->next->s_fanc->next->s_id);
	printf("init_friend_fir:%d\n",p_info->next->s_fanc->prev->s_id);
	search((void **)&(p_info->next->s_fanc));//测试
#endif
	return  0;
}
