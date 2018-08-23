#include<stdio.h>

int wei(int a);
int main()
{	
	int a,i;
	char c[11];
	printf("输入1个数");
	scanf("%d",&a);
	i=wei(a);
	c[i+1]='\0';
	if(a>0)
	c[0]='+';
	else if(a<0)
	{
		c[0]='-';
		a=-a;
	}
	for(i;i>=1;i--)
	{
		c[i]=a%10+48;
		a=a/10;
	}
//	for(n;n>=0;n--)
//	printf("%c",c[n]);
	puts(c);
	return 0;
}

int wei(int a)
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









































































































