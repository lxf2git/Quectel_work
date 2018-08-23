#include<stdio.h>
int main()
{
		char op;
		int  data1,data2,a;
		printf("data1 op data2\n");
		scanf("%d",&data1);
		
		scanf("%c",&op);
		
		
		scanf("%d",&data2);
		switch(op)
		{
		case '+':
				a=data1+data2;
				break;
		case '-':
				a=data1-data2;
				break;
		case '*':
				a=data1*data2;
				break;
		case '/':
				a=data1/data2;
				break;
		default:
				printf("erreo");
				break;
		}
		printf("%u\n",a);
		



return 0;
}
