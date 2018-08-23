#include<stdio.h>
int main()
{
	float data1, data2, data3;
	char a;
	printf("一个简单的算数式子\n");
	printf("每次输入完后以回车结束\n");
	printf("请输入第一个数:");
	scanf("%f",&data1);getchar();
	printf("+ — * /请选择一个运算符");
	scanf("%c",&a);
	/*while ('+' != a || '-' != a || '*' != a || '/' != a)
	{
		printf("请正确输入运算符\n");
		scanf("%c",&a);
	
	}*/
	printf("请输入第二个数:");
	scanf("%f",&data2);
	switch(a)
	{
	case '+' : data3 = data1 + data2;break;
	case '-' : data3 = data1 - data2;break;
	case '*' : data3 = data1 * data2;break;
	case '/' : while(0 == data2)
                {
			      printf("请重新输入一个非0的除数");
		    	  scanf("%f",&data2);
      		    } 
			   data3 = data1 / data2;break;
	default : printf("没有输入指定运算符\n");break;
	}
	printf("%.2f %c %.2f = %.4f\n",data1,a,data2,data3);
	return 0;
}
