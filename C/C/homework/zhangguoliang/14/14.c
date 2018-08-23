#include<stdio.h>
int bit();
int main()
{
	
	printf("输入一个正数：\n");
	bit();
	return 0;
}

int bit()
{
	int a,i;
	scanf("%d",&a);
	if(0<a&&a<10)
	{		i=1;
		printf("是%d位数\n",i);
	}
	else
	{	i=0;
		while(a>0)
		{
			a=a/10;
			i++;
		}
	printf("是%d位数\n",i);
	}
}
