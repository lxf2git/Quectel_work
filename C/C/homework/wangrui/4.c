#include<stdio.h>
 int main()
{
	float data1,data2,a;
	char op;
	int ch;
	printf("请输入data1 :");
	scanf("%f",&data1);
	printf("请输入data2 :");
	scanf("%f",&data2);
	printf("请选择运算 :");
	scanf("%c",&op);
	ch=getchar();
	switch(ch)
	{
			case 43: a=data1+data2;break;
			case 45: a=data1-data2;break;
			case 42: a=data1*data2;break;
			case 47: a=data1/data2;break;
			default: printf("error!");break;
	}
	printf("运算结果:%f\n",a);
	return 0;
}
