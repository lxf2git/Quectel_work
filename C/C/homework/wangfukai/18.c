#include<stdio.h>

int main()
{
	int a[10],max,min,i;
	float s;
	s=0;
	printf("请输入十个分数：");
	for(i=0;i<=9;i++)
	{
	 scanf("%d",&a[i]);
	s=s+a[i];
         min=max=a[0];
	if(max<a[i])
		{
        		max=a[i];
		}
		if(a[i]<=min)
		{
		min=a[i];
		}
	}
	s=(s-max-min)/8;
	printf("total:%f\n",s);
	return 0;
}
