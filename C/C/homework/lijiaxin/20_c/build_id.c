#include"main.h"
//void saveMenu();
//void withdrawMenu();
//void querMenu();
void showMenu()
{
		int i;
		do
		{
				printf("存款输入1，取钱输入2，查询输入3，退出输入0\n");
				scanf("%d",&i);
				switch(i)
				{
						case 1:saveMenu();break;
						case 2:withdrawMenu();break;
						case 3:querMenu();break;
						case 0:exit(0);
						default:break;
				}
		}while(1);
}

void saveMenu()
{
		int money1;

		     
			 
			printf("请输入存款金额 .\n");
			scanf("%d",&money1);
			money+=money1;
			printf("请确定存款金额%d .\n",money1);

			  
}
void withdrawMenu()
{
		int money2;
		char ch;
		do
		{
			printf("请输入取款金额(单比最多2000).\n");
			scanf("%d",&money2);
			printf("请确认取款金额%d y/n.\n",money);
			scanf("%c",&ch);
		}while(ch=='n');
		money-=money2;
		printf("\n");
}
void querMenu()
{
		printf("%d",money);
}
