#include<stdio.h>
int main()
{
		int d1,d2;
		char op;
		scanf("%c%d%d",&op,&d1,&d2);
		if(op=='+')
				printf("%d\n",d1+d2);
		else	if(op=='-')
				printf("%d\n",d1-d2);
		else	if(op=='*')
				printf("%d\n",d1*d2);
		else	if(op=='/')
				printf("%d\n",d1/d2);
		else 
				printf("我不会这个运算\n");
}
