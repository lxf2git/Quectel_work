#include<stdio.h>

int main()
{
	float sum=0,i=0;
	float high=100;
	int n;//是反弹的次数
	printf("请输入落地的次数：");
	scanf("%d",&n);

	for(sum += high;i<n;i++)
	{
		high = high/2;
		if(i == 0);
		else
			sum += high*4;
	
	}
	printf("当第十次落地时，总共经过%f米，第十次反弹%f米高\n",sum,high);
	return 0;
}
