#include<stdio.h>

int panduan(int);

int main()
{
	int shu, weishu;
	printf("请输入一个正整数");
	scanf("%d",&shu);
	weishu =  panduan(shu);
	printf("%d是%d位数\n",shu,weishu - 1);
}

int panduan(int shu)
{
	int weishu = 1, quyu = 1;
	for(;;)
	{
		if(shu % quyu == shu)
		break;
		quyu = quyu * 10;
		++weishu;
	}
	return weishu;
}
