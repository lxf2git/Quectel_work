#include<stdio.h>
int main()
{
		int a[10];
		int x,i,s;
		for(i=0;i<10;i++)
		{
				printf("请输入第%d个数：",i+1);
				scanf("%d",&a[i]);
		}
		printf("plese input x\n");
		scanf("%d",&x);
		for(s=0;s<10;s++)
		{
				if(x==a[s])
				{
						printf("已匹配%d,是第%d个数!\n",x,s);
						return 0;
				}
		}
		printf("Sorry,not found!");
}
