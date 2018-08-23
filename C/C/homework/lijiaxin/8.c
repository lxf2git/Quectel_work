#include<stdio.h>

int main()
{
	int i,j;
	float s=0;
	float high=100;
	printf("输入弹跳的次数:");
	scanf("%d",&i);
	for(j=1;j<=i;j++)
	{
		if(j==1)
		{
		 s=s+high;
		}
        high = high - high/2;
		if(j>1 && j<=i)
		{
		 s= high*4+s;	

		}
		
	}
	printf("%.2f %.2f\n",s,high);
	return 0;
}
