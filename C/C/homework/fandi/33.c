#include<stdio.h>
int main()
{
	int num_1=0,num_2=0;
	float sum_1=0,sum_2=0,average_1,average_2;
	int x;
	for(;;)
	{
		scanf("%d",&x);
		if(x%2==0&&x!=0)
		{
			num_1+=1;
			sum_1+=x;
			average_1=sum_1/num_1;
			if(num_1==0)
				average_1=0;
		}
		if(x%2!=0)
		{
			num_2+=1;
			sum_2+=x;
			average_2=sum_2/num_2;
			if(num_2==0)
				average_2=0;
		}
		if(x==0)
			break;
	}
	printf("输入的偶数总个数为:%d\n",num_1);
	printf("偶数的平均值为:%f\n",average_1);
	printf("输入的奇数总个数为:%d\n",num_2);
	printf("奇数的平均值为:%f\n",average_2);
	return 0;
}
