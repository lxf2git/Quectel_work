//1元兑换1分2分5分有多少种方式

#include<stdio.h>

int main()
{
	int shu = 0, geshi = 0;	//shu是结果多少种输出，geshi格式	
	int m1, m2, m5, money;			//循环条件控制
	int money1, money2, money5;  //循环变量
	printf("请输入你要兑换的钱（以元为单位）");
	scanf("%d",&money);
	m1 = money * 100;		//可以全兑换1分钱M1个
	m2 = money * 50;		//可以全兑换2分钱M2个
	m5 = money * 20;		//可以全兑换5分钱M5个
	for(money1 = 0;money1 <= m1;money1++)
	 {
		for(money2 = 0;money2 <= m2;money2++)
		{
			for(money5 = 0;money5 <=m5;money5++)
			{
				if((money1 + 2 * money2 + 5 * money5) == money * 100 )
					{
						printf(" %d一份钱%d贰分钱%d伍分钱 ",money1,money2,money5);
						shu++;
						geshi++;
						if(geshi % 3 == 0)
						{
							printf("\n");
						}
					}
			}	
		}
	}
	printf("\n%d一共%d种兑换可能\n",money,shu);
	return 0;
}
