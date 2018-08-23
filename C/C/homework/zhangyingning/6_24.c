#include<stdio.h>

int main()
{
	char aa[20] = {'0'};
	int a, b, c, d;
	printf("请输入一组字符");
	gets(aa);
	for(a = 0;a <= 20;a++)
	{
		if('c' == aa[a])
		{
			for(b = a; b <= 20;b++)
			{
				aa[b] = aa[b + 1];//将发现C 字符后面的字母全部前移一位
			}
			a--;//因为向左移动一位需要减去一位
		}
	}
	printf("输出结果:");
	puts(aa);
}
