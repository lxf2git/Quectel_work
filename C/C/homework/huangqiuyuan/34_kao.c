#include<stdio.h>
int main()
{
	int m,n,a,b;
	char i;
	printf("输入一个字符");
	scanf("%c",&i);
	printf("每行输入几个\n");
	scanf("%d",&m);
	printf("需要输出几行\n");
	scanf("%d",&n);
		for(a=0;a<n;a++)
		{
			for(b=0;b<m;b++)
			{	printf("%c",i);}
				printf("\n");
		}
	return 0;
}
