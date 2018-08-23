#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Own_zone(int confd)
{
	int ret;
	char user_name[20];
	PUser_info s_data;
	init_user_info(&s_data);
	read(confd,user_name,20);
	s_data = find_user(user_name);//获取用户信息
	PMicroblog blog = s_data->s_microblog->next;
	write(confd,s_data.s_user_basic_info->s_nick_name,20);//昵称
	while(blog!=s_data->s_microblog)
	{
		write(confd,blog->s_text,1024);//微博
		write(confd,&blog->s_praise,sizeof(int ));//赞
		blog=blog->next;
	}
	ret=0;
	write(confd,&ret,sizeof(int ));//发送完毕
}
