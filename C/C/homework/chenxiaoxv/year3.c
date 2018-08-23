#include<stdio.h>
int main()
{
 	int data1,data2,a;
  	char op;
  	printf("请输入数和运算符");
	 scanf("%d%c%d",&data1,&op,&data2);
	 if(op=='+')
	   a=data1+data2;
 	 else if(op=='-')
	   a=data1-data2;
 	 else if(op=='*')
	   a=data1*data2;
	 else if(op=='/')
	   a=data1/data2;
	 printf("a=%d\n",a);
	 return 0;
}
