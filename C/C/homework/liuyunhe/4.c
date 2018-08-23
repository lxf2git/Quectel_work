#include<stdio.h>
int main()
{
		printf("data1 data2 op 浮点型\n ");
		float data1,data2,a;
		char op;
		scanf("%f%f",&data1,&data2);
		getchar();
		scanf("%c",&op);
		if(op==42)
				a=data1*data2;
		else if(op==43)
				a=data1+data2;
		else if(op==45)
				a=data1-data2;
		else if(op==47)
				a=data1/data2;
		
		printf("%f\n",a);
		return 0;
}
