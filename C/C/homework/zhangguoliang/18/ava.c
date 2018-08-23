#include"ava.h"
int ava(int a[])
{	int sum=0,i;
	float z;
	for(i=1;i<9;i++)
	{
		sum+=a[i];
	}
	printf("sum=%d\n",sum);
	z=(sum)/8;
	printf("最后的平均分为:%.2f\n",z);
}
