//有20元，饮料一元一瓶，两个瓶盖可以换取一瓶意料，这些钱可以喝多少瓶饮料
#include<stdio.h>
//规律推出所喝的瓶数为钱数的2倍
//he = money * 2

int main()
{
	int ping, money, he = 0, dan;
	printf("请输入你有多少钱（元为单位)");
	scanf("%d",&money);
	ping = money;
	for (;;)
	{
		dan = 0;			//每次循环对dan初始化
		if (ping % 2 != 0)             //判断瓶盖是否为奇数
		{
			++dan;			//为奇数是dan加一
		}
		if (1 == ping)		//判断剩余瓶数是否为一
		{
			he +=1;
			break;
		}
		ping = ping / 2;    //瓶盖可兑换的瓶数
		he += ping;
		ping += dan;        //将除没的瓶盖加回来
	}
	printf("%d钱喝%d瓶",money,he + money);
	return 0;
}
