#include<stdio.h> 
void print(char ch,int bit,int list);
int main()
{
	char ch;
	int bit,list;
	printf("请输入输出字符。");
	scanf("%c",&ch);
	printf("请输入每行个数和行数。");
	scanf("%d%d",&bit,&list);
	print(ch,bit,list);
}
void print(char ch,int bit,int list)
{
	int bi=0,li=0;
	for(;li<list;li++)
	{
		bi=0;
		for(;bi<bit;bi++)
		{
			printf("%c",ch);
		}
		printf("\n");
	}
}
