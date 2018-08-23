#include<stdio.h>
void fun(char a,int b,int c);

int main()
{	int b,c;char a;
	printf("请输入要输出的字符a,每行的个数b，输入的行数c\n");
	scanf("%c",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	fun(a,b,c);
	
	return 0;
}
void fun(char a,int b,int c)
{
	int i;
	int d=0;
	for(i=1; i<=b*c;i++)
	{
		printf("%c",a);
		if(i%b==0)
		{
	
		printf("\n");
		d++;
		}
		if(d==c)
		break;
	}
}

