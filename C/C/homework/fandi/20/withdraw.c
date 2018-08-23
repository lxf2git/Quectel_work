#include"withdraw.h"



int withdrawMenu(int money)
{
	int money1,ch;
	printf("请输入取款金额:\n");
	for(;;){
	scanf("%d",&money1);
	if(money1<=money){
	money=money-money1;
	break;
	}
	else
		printf("余额不足，请重新输入\n");
	}
	printf("======================================\n");
	printf("           取款成功\n");
	printf("======================================\n");
	
	printf("1-------------查询余额\n");
	printf("2-------------切换账户\n");
	printf("3-------------退出\n");
	printf("请选择功能:\n");
	scanf("%d",&ch);
	switch(ch){
				case 1:
						queryMenu(money);
						break;
				case 2:
						main();
						break;	
				case 3:
						return 0;
	}
	return money;
}

