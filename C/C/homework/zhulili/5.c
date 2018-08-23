#include<stdio.h>
int main()
{
	int  n1,n2,n3,n;
	int total;
	n=0;
	for(n1=0;n1<=100;n1++)
	{
		for(n2=0;n2<=50;n2++)
			{
				for(n3=0;n3<=20;n3++)
					{
						total=n1+n2*2+n3*5;
						if(total==100)
						{
							n=n+1;
						}		
					}
			}
	}
	printf("输出方法的总数：%d\n",n);
	return 0;

}
