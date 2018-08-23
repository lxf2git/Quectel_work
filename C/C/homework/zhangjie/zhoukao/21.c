#include<stdio.h>

void count()
{
	int s,h=0;
	int i;
	int a[100]={0};
	printf("输入一个数\n");
	scanf("%d",&s);
	if(s==0)
	printf("0");
	else
	{
		for(i=0;;i++)
		{
			if(s%2==0)
			{
				a[i]=0;
			}
			if(s%2==1)
			{
				a[i]=1;
			}
			h++;
			if(s/2==0)
			{
				a[i]=1;
				h++;
				break;
			}
			s=s/2;		
		}
		for(i=h-2;i>=0;i--)
		{
			printf("%d",a[i]);
		}
	}
}

int main()
{
	count();
	return 0;
}

