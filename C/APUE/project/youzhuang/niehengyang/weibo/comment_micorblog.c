#include "../apue.h"
#include "../microblog.h"
#include "init.h"
void *Comment_micorblog(int confd,struct comment *comment)
{
	int ret;
	//PUser_info s_data;
	PMicroblog microblog;
	PComment s_node = comment ->next;
	init_microblog(&microblog);

	while(s_node!=comment)
	{
		write(confd,s_node->s_text,1024*10);//发送微博评论
		write(confd,s_node->s_user_name,strlen(s_node->s_user_name));//发送用户名
		s_node = s_node->next;
	}
	ret = 0;
	write(confd,&ret,sizeof(int ));//发完通知


	ret = read(confd,microblog->s_text,1024*10);

	add_back_com(comment,microblog->s_comment);


}
