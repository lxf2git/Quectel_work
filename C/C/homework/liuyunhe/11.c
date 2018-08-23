#include<stdio.h>

int max(int a,int b,int c);
int min(int a,int b,int c);
int main()
{int a,b,c;
 scanf("%d%d%d",&a,&b,&c);
 min(a,b,c);
 max(a,b,c);
 return 0;
}

int min(int a,int b,int c)
{ 
		int min;
		if(a>b)
		{
			min=b;
		}
		else
		{
			min=a;
		}

		if(min>c)
		{
			min=c;
			
		}
		else
		{
			;
		}
		printf("min=%d\n",min);
}

int max(int a,int b,int c)
{
		int max;
		if(a>b)
		{
				max=a;
		}
		else
		{
				max=b;
		}

		if(max>c)
		{
				;
		}
		else
		{
				max=c;
		}
		printf("max=%d\n",max);
}
