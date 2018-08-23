#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Del_microblog(int confd)
{
	int ret,num,i=1;
	char user_name[20];
	PUser_info data;
	init_user_info(&data);
	read(confd,user_name,20);
	data = find_user_name(user_name);//获取用户信息
	PMicroblog blog = data->s_microblog->next;
	read(confd,&num,sizeof(int ));//获取微博号
	while(blog!=data->s_microblog)
	{
		i++;
		if(i==num)
		{	
			ret =0;
			del_back_blog(&blog);//删除微博函数
			write(confd,&ret,sizeof(int ));
			return;
		}	
		
		blog = blog->next;
	}
	
		ret = -1;
		write(confd,&ret,sizeof(int ));
	

}
