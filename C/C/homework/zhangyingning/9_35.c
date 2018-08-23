#include<stdio.h>

int main()
{
	int str[20] = {0};
	int a, b;
	printf("请输入一个数");
	scanf("%d",&a);
	for(b = 0;b < 20;b++)
	{
		str[b] = a % 2;
	    a /= 2;
		if(0 == a / 2)
		{
			str[b + 1] = 1;
			break;
		}	
	}
	printf("\n");
	for(b += 1;b >= 0;b--)
	{
		printf("%d ",str[b]);
	}
	printf("\n");
}
