#define _XOPEN_SOURCE
#include "apue.h"
#define OK 1
#define FAIL 0
int child_log(struct ftp_usr_info user_info)
{
	printf("user:%s passwd:%s\n",user_info.ftp_usrname,user_info.ftp_passwd);
	struct spwd *pspwd=NULL;
	char *p=NULL;

	pspwd=getspnam(user_info.ftp_usrname);
	if(pspwd==NULL)
	{
		printf("user not exist.\n");
		return FAIL;//没有此用户
	}

	p=crypt(user_info.ftp_passwd,pspwd->sp_pwdp);
	if(strcmp(p, pspwd->sp_pwdp)==0)
	{
		printf("成功\n");
		return OK;//返回成功
	}
	else
	{
		printf("失败\n");
		return FAIL;//返回失败
	}
}
