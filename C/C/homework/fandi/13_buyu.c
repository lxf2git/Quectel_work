#include<stdio.h>
int main()
{
	int x,i,y,h;
	y=1;
	for(x=6;;x++)
	{
		for(h=x,i=1&&y;i<=5;i++)
		{
			if((h-1)%5==0)
			{	
				h=(h-1)*4/5;
			}
			else
			{
				y=0;
			}
		}
			if(y)
			{
				break;
			}
			else
			{
				y=1;
			}
		
	}
	printf("%d\n",x);
	return 0;
}
