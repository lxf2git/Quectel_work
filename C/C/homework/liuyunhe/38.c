#include<stdio.h>
int number(int x,int y)
{
		int s=1,i,a;
		for(i=0;i<y;i++)
		{
				s=s*x;
		}
		a=s%1000;
		printf("%d",a/100);
		printf("%d",(a%100)/10);
		printf("%d\n",a%10);
}
int main()
{
		int x,y;
		printf("输入整数\n");
		scanf("%d",&x);
		printf("输入次幂\n");
		scanf("%d",&y);
		number(x,y);
		return 0;
}
