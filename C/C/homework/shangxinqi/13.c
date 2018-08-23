#include<stdio.h>

int main()
{
	int a,b,c,d,e,i;
	i = 0;
	for(a=1;;a++)
	{
	if(a%5==1)
	{
	b=a-a/5-1;
	if(b%5==1)
	{
	c=b-b/5-1;
	if(c%5==1)
	{
	d=c-c/5-1;
	if(d%5==1)
	{
	e=d-d/5-1;
	if(e%5==1)
	{
			i=i+1;
	printf("最少捕获:%d条鱼\n",a);
	if(i>0)
					{
					break;
					}
	}
	}
	}
	}
	}

	
	
	
	
	}






















}
