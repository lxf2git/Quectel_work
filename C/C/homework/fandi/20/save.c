#include"save.h"



int saveMenu(int money)
{
	int money1,ch;
	printf("请输入存款金额:\n");
	scanf("%d",&money1);
			money=money+money1;
	printf("======================================\n");
	printf("           存款成功\n");
	printf("======================================\n");
	
	printf("1-------------取钱\n");
	printf("2-------------查询余额\n");
	printf("3-------------切换账户\n");
	printf("4-------------退出\n");
	printf("请选择功能:\n");
	scanf("%d",&ch);
	switch(ch){
				case 1:
						withdrawMenu(money);
						break;
				case 2:
						queryMenu(money);
						break;
				case 3:
						main();
				case 4:
						return 0;
	}
	return money;
}
