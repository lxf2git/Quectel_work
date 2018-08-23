#include "../apue.h"
#include "../microblog.h"

void *Login(int confd)
{
		printf("登录\n");
		int ret;
		PUser_basic_info data=NULL;//存用户基本信息
		data = (PUser_basic_info)malloc(sizeof(SUer_basic_info));
		PUser_info s_data;//存用户信息
		ret = read(confd,data,sizeof(SUer_basic_info));
		if(ret<0)
		{
				perror("login_read");
				exit(-1);
		}
		printf("%s  ",data->s_user_name);
		printf("%s  ",data->s_passwd);
		printf("%s\n",data->s_nick_name);
		s_data = find_user_name(data->s_user_name);
		if(s_data!=NULL)
		{
				if(strcmp(s_data->s_user_basic_info.s_passwd, data->s_passwd) == 0)
				{
						ret = SUC;
						write(confd,&ret,sizeof(int ));
				}
				else
				{
						ret = FAIL;
						write(confd,&ret,sizeof(int ));
				}
		}
		else
		{
				ret = FAIL;
				write(confd,&ret,sizeof(int ));
		}
		close(confd);
		return SUC;
}
