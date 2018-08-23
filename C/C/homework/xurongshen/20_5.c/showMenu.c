#include"my.h"

void showMenu()
{
	int i;
	printf("-----------------------------------------\n");
	printf("请输入一下的数字，选择您的功能！\n");
	printf("1:查询  2：存取款  3：保存  4：退出\n");
	printf("您输入的数是：");
	scanf("%d",&i);
	printf("-----------------------------------------\n");

	switch(i)
	{
		case 1:
				{
					void queryMenu();break;
			   	}
		case 2:
				{
					void moneyMenu();break;
			   	}
		case 3:
				{
					void saveMenu();break;
			   	}
		case 4:
				{
					void quitMenu();break;
			   	}

	}
//	return 0;

}
