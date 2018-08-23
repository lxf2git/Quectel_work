#include<stdio.h>
int main()
{
	int ji=0,ou=0,a;
	float sum1=0,sum2=0;
	while(1)
	{
		scanf("%d",&a);
		if(a!=0)
		{
			if(a%2==0)
			{
				sum2+=a;
				ou++;
			}
			else
			{
				sum1+=a;
				ji++;
			}
		}
		else
		break;
	}
	sum2=sum2/ou;
	sum1=sum1/ji;
	if(ji==0&ou==0)
	{
		sum2=0;
		sum1=0;
	}
	printf("偶数个数为%d，平均值是%f\n奇数个数为%d，平均值是%f\n",ou,sum2,ji,sum1);
	return 0;
}

