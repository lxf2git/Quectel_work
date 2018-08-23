#include<stdio.h>

int main()
{
	int money,i,j;
	j=0;
	do
	{		
	printf("你有多少钱\n");
	scanf("%d",&money);
	}while(money<1&&printf("滚回家拿钱\n"));
	for(i=1;i<=money;i++)
	{
		j++;
			if(j%2==0)
				j++;
	}
	printf("您能喝多少瓶饮料%d\n",j);
	return 0;
}
