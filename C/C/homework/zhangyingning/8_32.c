#include<stdio.h>
#include<string.h>
#define N 20
void bijiao(char arr[],char arr1[])
{
	int n, n1;
	int a, a1, a2 = 0;
	int b, c, c1 = 0, max = 0;
	int arr3[200] = {0};
	char arr4[20] = {'0'};
	n = strlen(arr);
	n1 = strlen(arr1);
	for(a = 0;a < n;a++)
	{
		c = 0;
		a1 = a;
		for(b = 0;b < n1;b++)
		{
			if(arr[a1] != arr1[b])
			{
				c = 0;		//内层循环清零
			}
			if(arr[a1] == arr1[b])
			{
				c++;		//存多少个一样的字符
				if(1 ==n)	//如果第一个数组长度为一不自增
				{
					;
				}
				else
				{
					a1++;	//让外层数组自增
				}
			}
			if(max <= c)
			{
				max = c;	//记录最长长度
				a2 = a;		//记录下标
			}
		}
	}
	for(a = 0;a < c1;a++)
	{
		printf(" %d ",arr3[a]);
	}
	if(0 == max)	 		//对长度进行判断
	{
		printf("无相同字符\n");
		return;
	}
	for(a = a2;a < max + a2;a++)
	{
		printf("%c",arr[a]);
	}
		printf("\n");
}

int main ()
{
	char arr[20] = {'0'}, arr1[20] = {'0'};
	int a, b, c;
	printf("请输入字符串");
	gets(arr);
	printf("请输入字符串");
	gets(arr1);
	bijiao(arr,arr1);
	return 0;
}
