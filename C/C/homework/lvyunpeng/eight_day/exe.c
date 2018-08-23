#include<stdio.h>
int recur(int a)
{
	int ret;
	if(a>0)
	{
		ret=a*recur(a-1);
	}
	else if(a==0)
	{
		ret=1;
	}
		return ret;

}
int main()
{
	int ret,i,a[10]={0},sum=0,n;
//	char m;
	printf("要输入几个数:");
	scanf("%d",&n);
	printf("请输入数字:");
	for(i=0;i<n;i++)
	{
		
		scanf("%d",&a[i]);
		printf("%d",a[i]);
	//	scanf("%c",&m);
	//	if(m=='\n')
	//	{
	//		return 0;

	//	}
	}
		for(i=0;i<n;i++)
		{
			ret=recur(a[i]) ;
			sum+=ret;
		}
		printf("sum:%d\n",sum);

}

