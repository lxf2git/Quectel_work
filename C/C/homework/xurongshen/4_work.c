#include<stdio.h>

int main()
{
	float data1,data2,sum=0;
	char op;

	printf("请输入俩个正整数：（输入以空格间隔）");
	scanf("%f%f",&data1,&data2);
	printf("\n请输入运算符号op=");
	getchar();
	scanf("%c",&op);
	//printf("%c\n",op);


	switch(op)
	{
		case '+':sum = data1 + data2;break;
		case '-':sum = data1 - data2;break;
		case '*':sum = data1 * data2;break;
		case '/':{
				 if(data2 == 0)
				 {	
				    printf("第二个数不为0！！！\n");
				  	printf("请输入俩个正整数：（输入以空格间隔）");
				 	scanf("%f%f",&data1,&data2);
				 }
					 
				 sum = data1 / data2;break;}
	}

/*
	if(op == '+')
		{
		printf("op等于+\n");
		sum = data1 + data2;
		}
	else if(op == '-')
		sum = data1 - data2;
	else if(op == '*')
		sum = data1 * data2;
	else if(op == '/')
		sum = data1 / data2;
*/
	printf("你的输出结果是：sum=%f\n",sum);
	return 0;
}
