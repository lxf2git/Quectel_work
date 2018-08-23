#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Del_microblog(int confd)
{
		printf("删除微博\n");
		int ret=0,num,i;
		char user_name[20];
		PUser_info data;
		read(confd,user_name,20);
		data = find_user_name(user_name);//获取用户信息
		PMicroblog blog = data->s_microblog->next;
		read(confd,&num,sizeof(int ));//获取微博号
		for(i=1;i<num&&blog!=data->s_microblog;i++)
		{
				blog = blog->next;
		}
		if(blog==data->s_microblog)
		{
				ret = -1;
				write(confd,&ret,sizeof(int ));
				close(confd);
				return;
		}
		del_back_blog(&blog);//删除微博函数
		write(confd,&ret,sizeof(int ));
		close(confd);
		return;
}
