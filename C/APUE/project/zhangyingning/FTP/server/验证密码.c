#define _XOPEN_SOURCE

#include"apue.h"
int login_user_psw(char *name,char *passwd)
//int main()
{
	printf("验证密码\n");
		struct spwd *pspwd=NULL;
		char *p=NULL;
		pspwd=getspnam(name);
	printf("程序:%s\n",name);
	printf("程序:%s\n",passwd);
		if(pspwd==NULL)
		{
	printf("名字错误\n");
				return 2;
		}
		p=crypt(passwd,pspwd->sp_pwdp);
		printf("lllllllllll\n");
	//	printf("p:%s\n",p);
	//	printf("name:%s\n",name);
			
		if(strcmp(p,pspwd->sp_pwdp)==0)
		{
	printf("密码正确\n");
				return 1;
		}
		else
		{
	printf("密码错误\n");
				return 2;
		}
	printf("不正常出去\n");
}
