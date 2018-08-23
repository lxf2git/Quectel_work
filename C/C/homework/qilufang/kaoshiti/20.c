#include<stdio.h>
void paixu(char a,int b,int c);
int main()
{
	int c=0,b=0;
	char a;
	printf("输入三个参数（一个字符,两个数字）:\n");
	scanf("%c%d%d",&a,&c,&b);
	paixu(a,b,c);
	return 0;

}
void paixu(char a,int b,int c)
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
