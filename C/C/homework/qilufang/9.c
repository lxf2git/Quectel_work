#include<stdio.h>

int main()
{
	printf("输入要花的钱数：\n");
	int mun=0,b=0,i;
	scanf("%d",&i);
	for(i;i>0;i--)
	{   
		mun++;
		b++;
		if(b%2==0)
		{
			b=b-1;
			mun++;
		}
	}
	printf("喝了%d瓶汽水 留了%d瓶子\n",mun,b);
	return 0;
}
