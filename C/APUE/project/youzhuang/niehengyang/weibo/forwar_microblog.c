#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Forwar_microblog(int confd,PMicroblog blog)//转发微博
{
	int ret;
	PUser_info s_node;
	init_user_info(s_node);
	char user_name[20];
	PMicroblog s_microblog;
	init_microblog(s_microblog);
	strcpy(s_microblog->s_text,blog->s_text);
	ret = read(confd,user_name,20);//获取转发用户昵称
	s_node = find_user_name(user_name);//获取转发用户信息
	ret = add_back_blog(s_node->s_microblog,s_microblog);//添加微博
	if(ret==SUC)
	{
		write(confd,&ret,sizeof(int ));
	} 
	else
	{
		ret=-1;
		write(confd,&ret,sizeof(int ));
	}
	bzero(s_node,sizeof(struct user_info));


}
