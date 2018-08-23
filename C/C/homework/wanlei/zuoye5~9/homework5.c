#include<stdio.h>

int main()
{
	int i,j,k,s,n;
	s=0;
	n=0;
	for(i=0;i<=100;i++)//100个一分硬币全部可能
	{
		for(j=0;j<=50;j++)//50个2分硬币的全部用法
		{
			for(k=0;k<=20;k++)//20个5分硬币的全部用法
			{
				s=i+(2*j)+(5*k);//列举所有的硬币用法
				if(s==100)//取他的成功用法。
				{
					printf("%d*1+%d*2+%d*5=100\n",i,j,k);
					n++;
				}
			}
		}
	}
	printf("%d\n",n);	
	return 0;
		
}
