#include<stdio.h>
int main()
{
	char ch;
	int cha,line;
	int i,j;
	printf("请输入字符数和行数:");
	scanf("%d %d",&cha,&line);
	getchar();
	printf("输入字符");
	scanf("%c",&ch);
	for(i=0;i<line;i++)
	{
		for(j=0;j<cha;j++)
		{
			printf("%c ",ch);
			
		}
		
		printf("\n");

	}





}

