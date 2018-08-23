#include<stdio.h>

int main()
{

	int data1=0,data2,result;
	char op;

	printf("Please input :data1 op data2\n");
	scanf("%d%c%d",&data1,&op,&data2);
		
	if('q'==data1)
		return 0;
	if ('+'==op)
		result=data1+data2;
	else if ('-'==op)
		result=data1-data2;
	else if ('*'==op)
		result=data1*data2;
	else if ('/'==op)
		result=data1/data2;
	else 
		{
			printf("ERR!\n");
			return 0;
		}

	printf("The result is %d\n",result);

	return 0;
}
