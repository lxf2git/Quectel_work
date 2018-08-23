#include<stdio.h>
int main()
{
		int i,d=0,p=0,y;
		printf("请输入要花的钱数");
		scanf("%d",&y);
		for(i=1;i<=y;i++)
		{
				d++;//喝了几瓶
				p++;//空瓶子个数
				if(p==2)
				{
					p-=2;
					i--;
				}
		}
		printf("哥们我一口气喝了%d瓶汽水\n还剩%d个空瓶子以后接着换\n",d,p);
}
