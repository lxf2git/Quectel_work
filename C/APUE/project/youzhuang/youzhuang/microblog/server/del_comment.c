#include "../apue.h"
#include "../microblog.h"
#include "init.h"

void *Del_comment(int confd,struct user_info *data,struct microblog* s_microblog)
{
		printf("del comment\n");
		int ret,num,i;
		char user_name[20];
		struct user_info *user;
		PComment comment = s_microblog->s_comment->next;
		read(confd,user_name,20);//获取用户名
		printf("user_name:%s\n",user_name);
		printf("data_name:%s\n",data->s_user_basic_info.s_user_name);
		user = find_user_name(user_name);
		read(confd,&num,sizeof(int ));//获取评论编号

		if(strcmp(data->s_user_basic_info.s_user_name,user_name)==0)
		{
				for(i=1;(i<num) && (comment!=s_microblog->s_comment) ;i++)
				{
						printf("**\n");
						comment=comment->next;
				}
				if(comment == s_microblog->s_comment)
				{
						ret=-1;
						printf("ret:%d\n",ret);
						write(confd,&ret,sizeof(int ));
						return;
				}
				else
				{
						printf("comment:%s\n",comment->s_text);
						ret = 0;
						del_back_comm(&comment);//删除评论
						write(confd,&ret,sizeof(int ));
						return;
				}
		}
		else
		{
				for(i=1; (i<num) && (comment!=s_microblog->s_comment) ;i++)
				{
						printf("^^\n");
						comment=comment->next;
				}
				if((comment == s_microblog->s_comment) || (strcmp(comment->s_nick_name,user->s_user_basic_info.s_nick_name)!=0))
				{
						ret= -1;
						printf("ret:%d\n",ret);
						write(confd,&ret,sizeof(int ));
						return;
				}
				else
				{
						printf("comment:%s\n",comment->s_text);
						ret = 0;
						del_back_comm(&comment);//删除评论
						write(confd,&ret,sizeof(int ));
						return;
				}
		}
}

