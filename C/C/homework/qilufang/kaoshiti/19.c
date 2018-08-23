#include<stdio.h>
void ou(int a[20],int b);
void ji(int a[20],int b);

int main()
{	
	int i,data[20]={0},a=0;
	printf("输入整数，直到输入0：\n");
	for(i=0;;i++)
	{
		scanf("%d",&data[i]);
		a=i;
		if(data[i]==0)
		break;
	}
	ou(data,a);
	ji(data,a);
	return 0;

}
void ou(int a[20],int b)
{
	int sum=0,i,nb=0;
	for(i=0;i<b;i++)
	{
		if(a[i]%2==0)
		{
			nb++;
			sum+=a[i];
		}	
	}
	printf("偶数有%d个，平均值是：%d\n",nb,sum/nb);
}
void ji(int a[20],int b)
{
	int sum=0,i,nb=0;
	for(i=0;i<b;i++)
	{
		if((a[i]+1)%2==0)
		{
			nb++;
			sum+=a[i];
		}	
	}
	printf("奇数有%d个，平均值是：%d\n",nb,sum/nb);
}
