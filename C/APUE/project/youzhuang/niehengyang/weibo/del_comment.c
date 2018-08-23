#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Del_comment(int confd,struct user_info *data,struct microblog* s_microblog)
{
	int ret,num,i;
	char user_name[20];
	PComment comment = s_microblog->s_comment->next;
	read(confd,user_name,20);//获取用户名
	read(confd,&num,sizeof(int ));//获取微博号
	if(strcmp(data->s_user_basic_info.s_user_name,user_name)==0)
	{
		while(comment!=s_microblog->s_comment)
		{
			i++;
			if(i==num)
			{
				ret = 0;
				del_back_comm(comment);//删除评论
				write(confd,&ret,sizeof(int ));
				return;
			}
			comment=comment->next;
		}
		ret=-1;
		write(confd,&ret,sizeof(int ));
		return;

	}
	else
	{
		while(comment!=s_microblog->s_comment)
		{
			i++;
			if(i==num&&strcmp(s_microblog->s_comment->s_user_name,user_name)==0)
			{
				ret = 0;
				del_back_comm(comment);//删除评论
				write(confd,&ret,sizeof(int ));
				return;
			}
			comment=comment->next;
		}
		ret= -1;
		write(confd,&ret,sizeof(int ));

		return;
	}

}

