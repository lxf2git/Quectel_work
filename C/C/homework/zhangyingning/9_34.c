#include<stdio.h>

void put_(char c,int a,int b)
{
	int a1,b1;
	printf("   1 2 3 4 5 6 7 8 9 10");
	for(a1 = 0;a1 < a;a1++)
	{
		printf("\n%d ",a1 + 1);

	for(b1 = 0;b1 < b;b1++)
	{
		printf(" %c",c);
	}
	}
	printf("\n");
}

int main()
{
	int a, b;
   	char c;
	printf("请输入要打印的行数\n");
	scanf("%d",&a);
	printf("请输入要打印的个数\n");
	scanf("%d",&b);
	printf("请输入要打印的字母\n");
	getchar();
	scanf("%c",&c);
	put_(c,a,b);
	return 0;

}
