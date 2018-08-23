#include<stdio.h>
int main()
{
int data1,data2;
char op;
scanf("%d%c%d",&data1,&op,&data2);
switch(op)
{
		case '+':
		printf("%d\n",data1+data2);
        break;

		case '-':
		printf("%d\n",data1-data2);
        break;

		case '*':
		printf("%d\n",data1*data2);
        break;

		case '/':
		printf("%d\n",data1/data2);
        break;
}
}
