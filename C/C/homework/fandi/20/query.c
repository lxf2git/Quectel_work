#include"query.h"



void queryMenu(int money)
{
	int ch;
	printf("账户余额为:%d\n",money);
	printf("1-------------取钱\n");
	printf("2-------------存款\n");
	printf("3-------------切换账户\n");
	printf("4-------------取钱\n");
	printf("请选择功能:\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			withdrawMenu(money);
			break;
		case 2:
			saveMenu(money);
			break;
		case 3:
			main();
		case 4:
			break;
	}

}
