#include "apue.h"
#include "microblog.h"

void *Login(int confd)
{

	int ret;
	PUser_basic_info data;//存用户基本信息
	PUser_info s_data;//存用户信息
	bzero(&data,sizeof(SUer_basic_info));
	ret = read(confd,data,sizeof(SUer_basic_info));
	if(ret<0)
	{
		perror("login_read");
		exit(-1);
	}
	s_data = find(data->s_user_name, data->s_passwd,&data->s_id,data->s_nick_name);
	if(s_data!=NULL)
	{
		ret = SUC;
		write(confd,&ret,sizeof(int ));
	}
	else
	{
		ret = FAIL;
		write(confd,&ret,sizeof(int ));
	}
	close(confd);
	return SUC;
}
