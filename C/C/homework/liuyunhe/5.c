#include<stdio.h>
int main()
{
		int a=0,d=0,i,j,m;
		for(i=0;i<=20;i++)
		{
				for(j=0;j<=50;j++)
				{
						for(m=0;m<=100;m++)
						{
								a=5*i+2*j+m;
								if(a==100)
									d=d+1;	
						}
				}
		}
		printf("%d\n",d);
		return 0;
}

