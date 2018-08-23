#include<stdio.h>
int main()
{
		int a,b,y;
		char p;
		printf("输入 数字 数字 运算符 \n");
		scanf("%d%d\n",&a,&b);
		scanf("%c",&p);
		if(p=='+')
		{	y=a+b;
		printf("%d\n",y);
		}
		if(p=='-')
		{
				y=a-b;
		printf("%d\n",y);
		}
		if(p=='*')
		{
				y=a*b;
		printf("%d\n",y);
		}
		if(p=='/')
		{
				y=a/b;
		printf("%d\n",y);
		}
		return 0;
}
