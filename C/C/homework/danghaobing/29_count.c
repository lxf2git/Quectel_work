#include<stdio.h> 
int main()
{
		char a;
		int i=0,m=0,n=0;

		printf("请输入几句话\n");
		for(;;)
		{
				scanf("%c",&a);
				if(a=='\n')
						break;
				if(a=='.')
						m++;
				if(a==' ')
				{
						n++;
				}
				i++;
		}
		printf("character=%d word=%d line=%d",i-m-n,m+n,m);
} 
