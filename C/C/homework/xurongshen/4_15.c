#include<stdio.h>

void print(int a);

int main()
{
	int d;
	printf("请输入一个正整数：（在100至500之内）");
	scanf("%d",&d);

	print(d);

	return 0;
}

void print(int a)
{
	int b=2,num=0,d,sum=0;
	//printf("print -->a=%d\n",a);
	//while(b<a)
	//{
	if(a>=100 && a<=500)
	{
		printf("b=%d\n",b);
		while(b<a)
		{
			if((a%b) == 0)
			{
			printf(" %d  ",b);
			num++;
			sum += b;
			}
			//if(num%5 == 0)//printf("b=%d",b);
			//	printf("\n");
			b++;
		}
	}
	else
	{
		printf("error!\n");
		printf("请输入一个正整数：（在100至500之内）");
		scanf("%d",&d);
		print(d);
	}
//	b++;
//	}
	printf("该正整数的约数个数num=%d\n",num);
	printf("该正整数的约数和是sum=%d\n",sum);

}
