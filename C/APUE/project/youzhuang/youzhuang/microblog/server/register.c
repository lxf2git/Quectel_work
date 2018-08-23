#include "../apue.h"
#include "../microblog.h"
#include "init.h"


void *Register(int confd)
{
		printf("注册\n");
		int ret;
		PUser_info data;
		init_user_info(&data);
		ret = read(confd,&data->s_user_basic_info,sizeof(SUer_basic_info));
		printf("%s\n",data->s_user_basic_info.s_nick_name);
		printf("%s\n",data->s_user_basic_info.s_user_name);
		printf("%s\n",data->s_user_basic_info.s_passwd);
		printf("%s\n",data->s_user_basic_info.s_sex);
		printf("%d\n",data->s_user_basic_info.s_age);
		if(ret<0)
		{
				perror("register_write");
		}
		if(NULL==find_user_name(data->s_user_basic_info.s_user_name) && NULL == find_nick(data->s_user_basic_info.s_nick_name))
		{
				data->s_user_basic_info.s_id = user_id++;
				printf("id:%d\n",user_id);
				ret = add_back_info(puihead,data);
				write(confd,&ret,sizeof(int ));
		}
		else
		{
				if(NULL==find_user_name(data->s_user_basic_info.s_user_name))
				{
						ret = -1;
						write(confd,&ret,sizeof(int ));
				}
				if(NULL == find_nick(data->s_user_basic_info.s_nick_name))
				{
						ret = -2;
						write(confd,&ret,sizeof(int ));
				}
		}
		close(confd);
}
