#include"my.h"

long id;
int password;

int main()
{
	int id,passwd;
	printf("请输入你的卡号，密码：（以间隔隔开）：\n");
	scanf("%d %d",&id,&passwd);
	printf("你的卡号%d，密码：%d\n",id,passwd);
	judgeId(id,passwd);
//	showMenu();
	printf("main--->success\n");
	return 0;
}
