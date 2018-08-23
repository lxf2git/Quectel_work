#include<stdio.h>
int weishu(int a);

int main()
{
		int a,b,n,c[10],i;
		printf("请输入一个数：\n");
		scanf("%d",&a);
		if(a<0)
		{
			c[0]='-';
			a=a*-1;
		}
		else
		{
			c[0]='+';		
		}
		n=weishu(a);
		for(i=n;i>0;i--)
		{
				c[i]=a%10+48;
				a=a/10;
		}
		for(i=0;i<n+1;i++)
		{
				printf("%c",c[i]);
		}
		return 0;
}

int weishu(int a)
{
		int i;
		for(i=1;;i++)
		{
				a=a/10;
				if(a==0)
				{
					break;
				}

		}
	return i;
}
