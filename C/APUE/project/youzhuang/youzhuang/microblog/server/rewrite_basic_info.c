#include "../apue.h"
#include "../microblog.h"
#include "init.h"


void *Rewrite_basic_info(int confd)
{	
		printf("修改密码\n");
		int ret;
		char user_name[20];
		char passwd[20];
		char new_passwd[20];
		PUser_info data;
		read(confd,user_name,20);//读取用户名
		read(confd,passwd,20);//读取旧密码
		data = find_user_name(user_name);//获取用户信息
		printf("passwd:%s\n",passwd);
		if(strcmp(data->s_user_basic_info.s_passwd,passwd)==0)//检验旧密码
		{
				ret =0;
				write(confd,&ret,sizeof(int ));//验证旧密码成功
				read(confd,new_passwd,20);//获取新密码
				printf("new:%s\n",new_passwd);
				strcpy(data->s_user_basic_info.s_passwd,new_passwd);//修改密码
				write(confd,&ret,sizeof(int ));//密码修改完成
				close(confd);
		}
		else
		{
				ret =-1;
				write(confd,&ret,sizeof(int ));
				close(confd);
		}
	
		
}
