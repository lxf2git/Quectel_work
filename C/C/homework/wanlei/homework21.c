#include<stdio.h>
#include<stdlib.h>

int ws(int x);
int equal(int x);

int main()
{
	int a,i,j,b;
	char ch[20]={};
	printf("please input a number\n");
	scanf("%d",&a);
	if(a<0)
	{
		ch[0]='-';
		a=abs(a);
		i=ws(a);
		ch[i]=a%10+48;
		b=i-1;
		for(j=1;j<i;j++)
		{	
			ch[j]=a/equal(b)+48;
			a=a-(a/equal(b))*equal(b);
			b--;

		}
		for(j=0;j<i;j++)
			printf("%c",ch[j]);
	}
	if(a>0)
	{
		i=ws(a);
		ch[i-1]=a%10+48;
		b=i-1;
		for(j=0;j<i-1;j++)
		{	
			ch[j]=a/equal(b)+48;
			a=a-(a/equal(b))*equal(b);
			b--;
		}
	for(j=0;j<i;j++)
		printf("%c",ch[j]);
	}
	printf("\n");
	return 0;
}

int ws(int x)
{
	int i=0;
	do
	{
		x/=10;
		i++;
	}while(x!=x/10);
	return i;
}
#if 1
int equal(int x)
{
	int a=1;
	int	i;
	for(i=1;i<=x;i++)
	{
		a=a*10;
	}
	return a;
}
#endif
