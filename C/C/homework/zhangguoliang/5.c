#include<stdio.h>
int main()
{
	int a,b,c,y,i=0;
	for(a=0;a<=100;a++)
	{
		for(b=0;b<=100;b=b+2)
		{
			for(c=0;c<=100;c=c+5)
			{
				y=a+b+c;
					if(y==100)
						i++;
			}
		}
	}
	printf("方法数：%d\n",i);
	return 0;
}
