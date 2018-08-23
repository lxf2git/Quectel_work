#include<stdio.h>

int merge(int a,int b);

int main()
{
		int a,b,c;
		printf("请输入两个10～99之间的数:\n");
		scanf("%d",&a);
		scanf("%d",&b);
		printf("a:%d\n",a);
		printf("b:%d\n",b);
		printf("c:%d\n",merge(a,b));
		return 0;
}

int merge(int a,int b)
{
		int c;
		c=a/10*100+a%10+b/10*10+b%10*1000;
		return c;
}
