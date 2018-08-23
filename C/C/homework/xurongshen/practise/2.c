#include<stdio.h>
#define N 100
void print(char ch, int num, int low);
int main()
{
	char ch;
	int m,n;
	printf("请输入字符:");
	scanf("%c",&ch);
	printf("请打印的行数:");
	scanf("%d",&m);
	printf("请打印的个数:");
	scanf("%d",&n);

	print(ch,m,n);
	return 0;
}

void print(char ch, int num, int low)
{
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<low;j++)
		{
			printf("%c",ch);
		}
		printf("\n");
	}
}
