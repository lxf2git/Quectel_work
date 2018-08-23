#include<stdio.h>
int main()
{
	int i=1,k,money;
	printf(" 请输入所有金钱：");
	scanf("%d",&k);
	for(money=k;money>=1;money--)
	{
		i++;
		while(money<=k/2)	
		{
			k=k/2;
			i=i+k;
		}	
		if(k/2==1&&k%2==1)
	{
		i=i+1;
	}
	}
	printf("最多能喝到%d瓶汽水！\n",i);


}
