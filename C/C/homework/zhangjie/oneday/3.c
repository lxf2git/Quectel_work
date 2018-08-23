#include<stdio.h>
int main()
{
	char op;
	int data1,data2;
	printf("请输入运算式\n");
	scanf("%d%c%d",&data1,&op,&data2);
	getchar();
	switch(op)
	{
		case '+':
		printf("结果为%d\n",data1+data2);
		break;
		case '-':
		printf("结果为%d\n",data1-data2);
		break;
		case '*':
		printf("结果为%d\n",data1*data2);
		break;
		case '/':
		printf("结果为%d\n",data1/data2);
		break;
		default:
		printf("请重新输入运算式\n");
		break;
	}
	return 0;
}
