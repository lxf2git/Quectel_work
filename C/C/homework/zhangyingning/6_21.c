#include<stdio.h>

int main()
{
	int a = 0, c, d = 0,e,f;
	char aa[10] = {'0'}, fu ;

	printf("请输入一个四位以下数");
	scanf("%d",&c);
	if(c < 0)
	{
		c *= -1;
		c = 1;
		aa[0] = '-';
	}
	for(a = 10000;a > 0;a / 10)
	{
		f = c;
		if(f / a == 0)
		{
			continue;
		}
		e = c / a;
		c = c - e * a;
		aa[d] = e;
	    d++;	
	printf("%d",a);
	}
    for(a = 0;a < 10;a++ )
	{
		printf("%C",aa[a]);
	}
}
