#include<stdio.h>
int main()
{
	int a[100]={0},j=0,z=0,sum1=0,sum2=0,i;
	printf("请输入整数:");
	for(i=0;;i++)
{
	scanf("%d",&a[i]);
//	printf("%d",a[i]);
	if(a[i]!=0)
	{
//		printf("%d",a[i]);
		if(a[i]%2==0)
		{
			j++;
			sum1+=a[i];
//			printf("%d %d",j,sum1);
		}
		if(a[i]%2==1)
		{
			z++;
			sum2+=a[i];
//			printf("%d %d",z,sum2);
		}
	}
	else
	{
		printf("偶数总个数:%d",j);
		printf("偶数平均值:%d",sum1/j);
		printf("奇数总个数:%d",z);
		printf("奇数平均值:%d",sum2/z);

		return 0;

	}

		
	

}

		return 0;



}

