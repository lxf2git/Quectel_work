#include<stdio.h>

int main()
{
	int data1,data2,a;
	char op;
	printf("请输入运算符和两个数\n");
	scanf("%d%c%d",&data1,&op,&data2);
	getchar();
	switch(op)
	{
		case '+':
				printf("data1%cdata2=%d\n",op,data1+data2);
				break;
		case '-':
				printf("data1%cdata2=%d\n",op,data1-data2);
				break;
		case '*':
				printf("data1%cdata2=%d\n",op,data1*data2);
				break;
		case '/':
				printf("data1%cdata2=%d\n",op,data1/data2);
				break;
		default:
				printf("输入错误\n");
				break;
	}
	return 0;
}
