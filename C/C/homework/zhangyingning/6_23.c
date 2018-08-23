#include<stdio.h>

int main()
{
	int aa[10] = {0};
	int a, b, c, d, e = 2;
	printf("请输入十个数,每个数以空格间隔");
	for(a = 0;a < 10;a++)
	{
		scanf("%d",&aa[a]);
		getchar();
	}
	for(a = 0;a < 10 ;a++)
	{
		for(b = a;b <10;b++)
		{
			if(aa[a] > aa[b])
			{
				c = aa[a];
				aa[a] = aa[b];
				aa[b] = c;
			}
		}
	}
	for(a = 0;a < 10;a++)
	{
		printf(" %d ",aa[a]);
	}
	printf("请输入要排列的位子");
	do
	{
		scanf("%d",&a);
	}
	while((a < 0 || a > 10) && printf("超出范围请重新输入"));
	printf("要排列的个数个数");
	do
	{
		scanf("%d",&b);
	}
	while(b > 10 - a && printf("超出范围请重新输入"));
	if (a = b)//一旦移动的位数和移动位相等直接输出
	{
       ;
	}
   else
   {
	 for(c = a -1;c <= a + b / 2 - 1;c++)//数组从0开始需要减1
	{
		d = aa[c];
		aa[c] = aa[a + b - e];
		aa[a + b - e] = d;
		e++;//此数决定最后一位
	}
   }
	for(a = 0;a < 10;a++)
	{
	printf(" %d ",aa[a]);
	}
	
}







