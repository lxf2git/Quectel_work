#include<stdio.h>

int main()
{
	int total=0;
	int money;
	while(total<=1000)
	{
		printf("我的钱不够1000 再给点吧\n");
		scanf("%d",&money);
		total+=money;//total = total+money;
	}	

	printf("我的钱：%d\n",total);
	return 0;
}
