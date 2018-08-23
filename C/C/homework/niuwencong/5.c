#include<stdio.h>
int main()
{
	int a=1,b=2,c=5;
	int x,y,z,n=0;
	for(x=0;x<=100;x++)
	{
		for(y=0;y<=50;y++)
		{
			for(z=0;z<=20;z++)
			{
				if(x*a+y*b+z*c==100)
				{	n=n+1;
					printf("您可以用%d个1分%d个2分%d个5分兑换\n",x,y,z);
				}
				else 
					continue;
 			}
		}
	}
	printf("总上所示，共有%d种兑换方法\n",n);
return 0;
}
