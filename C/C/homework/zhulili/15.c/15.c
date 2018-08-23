#include<stdio.h>
//

int yueshu(int x);

int main()
{
	int x;
	scanf("%d",&x);
	x=yueshu(x);
	return 0;
}

int yueshu(int x)
{
	int number,sum=0;
	int i=2;
	number=0;

		for(i=2;i<x;i++)
		{
			if(x%i==0 && x>=100&& x<=500)
			{
				printf("约束有：%d\n",i);
				number+=1;
				sum=sum+i;
			}
		}
	
	printf("约数的个数：%d\n",number);
	printf("约数的总和：%d\n",sum);
	return i;
}
