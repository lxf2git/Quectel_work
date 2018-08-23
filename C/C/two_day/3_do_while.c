#include<stdio.h>
//冗错
int main()
{
	int choose;	
	do
	{
		printf("1--存款\n");
		printf("2--转账\n");
		printf("3--查询\n");
		printf("4--取款\n");
		printf("0--退出\n");
		scanf("%d",&choose);
	
	}while((choose<0||choose>4)&&printf("please input again!\n"));	
	printf("您选择的是：%d\n",choose);
	return 0;
}


