#include<stdio.h>

int main()
{
	int n,m,a,b;
	int s,p,lend;
	n=0;
	b=0;
	a=0;
	
	printf("拥有钱数:");
	scanf("%d",&m);
	printf("单价:");
	scanf("%d",&s);
	printf("换水瓶数:");
	scanf("%d",&p);
	printf("可不可借:");
	scanf("%d",&lend);

	if(lend!=0)lend=1;
	else lend=0;

	if(p>1&&m>=s)
	{
		n=m/s;
		b=n;
		while(b>=1)
		{
			a=a+b%p;
			b=b/p;
			n=n+b;
			if(a+lend==p)
			{	
				n++;
				a=0;	
			}
		}

		printf("可买%d瓶水\n",n);
	}
	else if(p==1&&m>=s)
	{
		printf("尽情的喝吧!\n");
	}
	else 
	{
		printf("error!\n");
	}
	return 0;
}

