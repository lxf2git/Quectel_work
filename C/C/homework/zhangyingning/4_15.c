
#include<stdio.h>


int main()
{
	int ys = 0;
	printf("请输入一个100～500的数");
	scanf("%d",&ys);
	while(ys <= 100 || ys >= 500)
	{
		printf("请重新输入");
		scanf("%d",&ys);
	}
	printf("%d的约数是\n",ys);
	int a, jia = 0;
	for(a = 2;a < ys;a++)
	{
		if(ys % a == 0)
		{
			printf(" %d ",a);
			jia += a;
		}
	}
	printf("\n");
	printf("%d的约数和是%d\n",ys,jia);
}
