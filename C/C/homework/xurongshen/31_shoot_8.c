#include<stdio.h>
#define N 10
void acount(int arr[N],int b);
int main()
{
	int arr[N]={0},n,i;
	printf("input n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{arr[i]=1;}
	for(i=0;i<n;i++)
	{printf("arr[%d]:%d\n",i,arr[i]);}
	acount(arr,3);
	return 0;
}

void acount(int arr[N],int b)
{
	int sum=0,a=N,i;//a表示存活的个数，
	int t=0,k=0;
	for(i=0;i<N;)
	{
		sum = sum+arr[i];
		if(sum == b)
		{
			arr[i] = 0;
			printf("第%d个是arr[%d]\n",i+1,arr[i]);
			a--;
			sum = 0;

		}
		if(sum<b && a<b)
		{
			printf("sum:%d a:%d\n",sum,a);
				/*********
			if(arr[i]==1)
			{
				printf("%d存活a[i]:%d\n",i+1,arr[i]);
				break;
			}
			************/
			i=0;
			while(1)
			{
				if(arr[i] == 1)
				{
				printf("aaaaaaaaaaaaaaa\n");
				sum=sum+arr[i];
				printf("sum:%d,i:%d\n",sum,i);
				if(i>=10)
				{
				printf("bbbbbbbbbbbb\n");
					i=i%10;
				}
				if(sum == 3)
				{
					sum =0;
					arr[i] = 0;
				printf("ccci%d\n",i);
					a--;
					if(a == 1)
					{
				printf("a=%d....\n",a);
						if(arr[i] == 1)
						{
							printf("存活i%d\n",i);
							
						}
							break;
					}
				}
				}
				i++;
			}
					if(arr[i] == 1)
					{
						printf("第%d个数存活\n",i+1);
						break;
					}

			break;
		}
		i++;
		if(i>=10)
		{
			i=i%10;
		}
	}
}
