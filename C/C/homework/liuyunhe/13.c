#include<stdio.h>
int xunhuan();
int main()
{
		xunhuan();
		return 0;
}
int xunhuan()
{
		int a,b=1,i=1,j=0;
		int m,n;
		while(j<4)
		{
		if((b%5==1)&&(b%4==0))
		{		
			a=b*5/4+1;
			b=a;
			j++;
		//printf("%d\n",j);
		}
		else
		{
				i++;
				b=i;
				j=0;
		//printf("%d\n",b);
		}
		}
		printf("%d\n",b);
}
