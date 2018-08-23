#include<stdio.h>
int main()
{
	int a,b,c,i=0,j=0;
	for(a=0;a<=100;a++)
	{
		for(b=0;b<=50;b++)
		{
			for(c=0;c<=20;c++)
			{
				i=a+(2*b)+(5*c);
				if(i==100)
				j++;
			//	printf("%d,%d,%d\n",a,b,c);
			}
		}
	}
	printf("共有%d种兑换方法\n",j);
	return 0;
}
