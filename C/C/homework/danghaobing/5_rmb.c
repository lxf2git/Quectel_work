#include<stdio.h>
int main()
{
		int t=0;
		int i,n,s;
		printf("一元人民币兑换成分有几种呢?\n");
		for(i=0;i<=100;i++)
		{
				for(n=0;n<=50;n++)
				{
						for(s=0;s<=20;s++)
						{
								if(i+2*n+5*s==100)
										t++;
						}
				}
		}
		printf("%d\n",t);
		return 0;
}
