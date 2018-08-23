#include"my.h"

int judgeId(int id,int passwd)
{
	printf("judgeId--->success\n");
	int i;
	int balance,password=1;
	for(i=0;i<=id;)
	{
		if((i == id) && (passwd == password))
		{
			printf("id:%d passwd:%d",&id,&passwd);
			printf("judgeId will into showmenu--->success\n");
			showMenu();
		}
		else
		{
//			printf("登录错误！\n");
		}
		i++;
		if(i>id)
		{
			printf("judgeId will into creat--->success\n");
			 creat();
			printf("judgeId creat--->success\n");
		}
	}
}
