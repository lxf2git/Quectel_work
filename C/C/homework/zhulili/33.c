#include<stdio.h>

int main()
{
	int i,n;
	int n1=0;
	int sum1=0;
	int sum2=0;
	int n2=0;
	float average1,average2;
	for(n=10;n>0;n--)
	{
		scanf("%d",&i);
		getchar();
		if(i%2==0)
		{
			n1+=1;
			sum1+=i;
			average1=sum1/n1;
		}
		if(i%2==1)
		{
			n2=n2+1;
			sum2+=i;
			average2=sum2/n2;
		}
	}
	printf("输出偶数数与奇数数：%d,%d\n",n1,n2);
	printf("输出偶数平均值与奇数平均值：%f,%f\n",average1,average2);

	return 0;
}
