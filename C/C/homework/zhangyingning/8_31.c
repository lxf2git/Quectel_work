#include<stdio.h>
#define N 10 //10个人

int main()
{
	int arr[N];
	int a, b, c = 1, d = 0;
	for(a = 0; a < N;a++)//对数组初始化1
	{
		arr[a] = 1;
	}
	for(a = 0;a <= 9;a++)
	{
		if (arr[a] != 0)//判断是否死亡
		{
			if(c % 3 == 0)//每三人杀死一个
			{
				arr[a] = 0;//杀死
				d++;
				if(d == N - 1)//还剩1人推出
				{
					break;
				}
			}
			c++;//取余自增
		}
		if(a == N - 1)//让A 再0～9循环
		{
			a = -1;
		}
	}

	for(a = 0;a < N;a++)
	{
		if(arr[a] == 1)
		{
			printf("%d个人，活下来的人是%d号\n",N,a + 1);
		}
	}

}
