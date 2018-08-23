#include"my.h"

void moneyMenu()
{
	int i;
	printf("请输入你要选择的类型：(1:存款  2：取款  3：显示余额  4：返回主菜单");
	printf("\n您输入的数是：");
	scanf("%d",&i);
	printf("-----------------------------------------\n");

	switch(i)
	{
		case 1:
				{
					void inputMoney();break;
			   	}
		case 2:
				{
					void withdrawMoney();break;
			   	}
		case 3:
				{
					void saveMoney();break;
			   	}
		case 4:
				{
					void showMenu();break;
			   	}

	}
//	return 0;

}
