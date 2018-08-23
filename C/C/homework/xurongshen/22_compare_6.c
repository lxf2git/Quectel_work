#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 200

void  put_in(char arr[N]);
void compare(char arr[N]);
void put_out(char brr[N]);

int main()
{
	int b;
	char arr[N]={'0'};
	printf("请输入一个字符串:");
	put_in(arr);
	printf("put_in -->arr跳出！:\n");
	put_out(arr);
	compare(arr);
	printf("compare-->arr:\n");
	put_out(arr);
	return 0;
}

void  put_in(char arr[N])
{
	int i;
	printf("put_in into:\n");
	for(i=0;i<N;i++)
	{
		scanf("%c",&arr[i]);
		if(arr[i] == 10)
			break;
//		compare(arr[N],arr[i]);
	}
}
void put_out(char brr[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%c",brr[i]);
	}
	printf("\n");
}
void compare(char arr[N])
{
	int n;
	n = strlen(arr);
		int i,j;
		char k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				k = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = k;
			}
		}
	}
}
