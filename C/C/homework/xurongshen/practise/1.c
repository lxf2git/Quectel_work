#include<stdio.h>
#define N 100
int main()
{
	int i,a=0,b=0,an=0,bn=0;
	int arr[N]={0};

	for(i=0;i<N;i++)
	{
		printf("%d的值是",i);
		scanf("%d",&arr[i]);
		if(arr[i] == 0)
		{
		//ZZ	arr[i]='\0';
			break;
		}
			if(arr[i]%2 == 0)
			{
					a++;
					an += arr[i];
			}
			else
			{
				b++;
				bn+=arr[i];
			}
	}
	printf("奇数个数：%d,平均值：%f\n",b,bn*1.0/b);
	printf("偶数个数：%d,平均值：%f\n",a,an*1.0/a);
}
