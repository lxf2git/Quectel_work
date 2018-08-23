#include<stdio.h>
int main()
{
	int d,c,x;
	char op; 
	
	scanf("%d%c%d",&d,&op,&c);
	if (op=='+')
{	x=d+c;
	printf("%d\n",x);
}
	else if	 (op=='*')
{	x=d*c;
	printf("%d\n",x);
}

         else if  (op=='-')
{	x=d-c;
	printf("%d\n",x);
}
           else if (op=='/'&&c!=0)
{	x=d/c;
	printf("%d\n",x);
}
	else
	printf("输入错误\n");


	return 0;
}
