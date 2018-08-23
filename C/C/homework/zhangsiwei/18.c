#include<stdio.h>
int max(int a[]);
int min(int a[]);
int average(int a[]);



int main()
{
	int i,a[10];
	printf("请评委打分：\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	min(a);
/*	for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}printf("\n");
*/	max(a);
/*	for(i=0;i<10;i++)
	{
		printf("%d  ",a[i]);
	}printf("\n");
*/	average(a);
		

	return 0;
}
int min(int a[])
{
	int i,t;
	for(i=0;i<10;i++)
	{
			if(a[0]>a[i])
			{
					t=a[0];
					a[0]=a[i];
					a[i]=t;
				//	printf("%d我是min\n",a[i]);
			}
	}
					printf("min=%d\n",a[0]);
}
int max(int a[])
{
	int t,i;
	for(i=0;i<10;i++)
	{
		if(a[9]<a[i])
		{
				t=a[9];
				a[9]=a[i];
				a[i]=t;
		}
	}
					printf("max=%d\n",a[9]);
}
int average(int a[])
{
	int i,t;
	t=0;
	for(i=1;i<9;i++)
	{
		t=t+a[i];
	//	printf("%d\n",t);
	//	printf("%d   ",a[i]);
	}
	printf("平均分：%d\n",t/8);
}
