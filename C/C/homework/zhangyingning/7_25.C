#include<stdio.h>

int main() 
{
	int a, b, c, d;
	printf("请输入一个数");
	scanf("%d",&c); 
	for(a = 0 ;a  < c;a++)
	{
		for(b = 0;b < c;b++)
		{
			d = a - b + 1;
			if(d <= 0)
			{
				d = 1;
			}
			printf("%5d",d);
		}
		printf("\n");
	}
}
