#include "../apue.h"

int main()
{
		struct spwd *pspwd=NULL;
		char user_name[1024];
		char *user_passwd;
		char *p=NULL;

		bzero(user_name, sizeof(user_name));
		//bzero(user_passwd, sizeof(user_passwd));

		printf("input user name:");
		scanf("%s", user_name);
#if 0
		printf("input user passwd:");
		scanf("%s", user_passwd);
#endif
		//获取隐身密码：参数是提示信息，返回值是输入数据
		user_passwd=getpass("input user passwd:");
		//匹配
		pspwd=getspnam(user_name);
		//判断输入的用户名在系统中是否存在 
		if(pspwd==NULL)
		{
				printf("user not exist.\n");
				return -1;
		}
		//判断输入的密码是否与系统用户对应密码匹配
		p=crypt(user_passwd, pspwd->sp_pwdp);
		if(strcmp(p, pspwd->sp_pwdp) == 0)
		{
				printf("login success.\n");
		}		
		else
		{
				printf("login failed.\n");
		}

		return 0;
}







