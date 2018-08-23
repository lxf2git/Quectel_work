#include"main.h"

void showMenu()
{
	int a;
	do
	{
		printf("1.查询余额\n");
		printf("2.创建账户\n");
		printf("3.存款\n");
		printf("4.取款\n");
		printf("5.退出程序\n");
		printf("请选择功能\n");
		scanf("%d",&a);
		if(a==1)
			queryMenu();
		else if(a==2)
		{
			creatMenu();
			password(id);
		}
		else if(a==3)
			saveMenu();
		else if(a==4)
			withdrawMenu();
		else
			exit(0);
	}while(a!=5);
}
