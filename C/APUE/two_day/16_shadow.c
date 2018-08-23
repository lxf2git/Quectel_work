#include "../apue.h"

int main()
{
	struct spwd *pspwd=NULL;
#if 0
	pspwd=getspnam("root");
	if(pspwd==NULL)
	{
			perror("getspnam");
			return -1;
	}
#endif
	//获取登录用户的信息
	//pspwd=getspent();
	
	//打开/etc/shadow
	setspent();
	
	while(1)
	{
		//到文件/etc/shadow读取数据，返回值为NULL表示读取结束
		pspwd=getspent();
		if(pspwd==NULL)
		{
				break;
		}
		printf("name=%s pwd=%s\n", pspwd->sp_namp, pspwd->sp_pwdp);
	}
	//关闭/etc/shadow
	endspent();

	return 0;
}






