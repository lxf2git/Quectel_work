#include<stdio.h>
void fun(char a,int b,int c);
int main()
{
	char a;
	int b,c;
	printf("你要输入的字符是:\n");
	scanf("%c",&a);
	printf("输入每行字符输入的个数b\n");
	scanf("%d",&b);
	printf("输入输出的行数c\n");
	scanf("%d",&c);
	fun(a,b,c);

}
void fun(char a,int b,int c)
{
	int i,j;
	for(i=0;i<c;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("%c",a);
		}
		printf("\n");
	}
	
}
