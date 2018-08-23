#include<stdio.h>
int main()
{
	int data1,data2,a;
	char op;
	printf("input  data1 op data2\n");
	scanf("%d%c%d",&data1,&op,&data2);

	switch(op)
	{
			case '*':
                    a=data1*data2;
					printf("%d\n",a);
					break;
			case '+':
					a=data1+data2;
					printf("%d\n",a);
					break;
			case '-':

                    a=data1-data2;
					printf("%d\n",a);
					break;
			case '/':
					a=data1/data2;
					printf("%d\n",a);
					break;
	
            defalt:
					printf("error\n");
					break;
	}
}
