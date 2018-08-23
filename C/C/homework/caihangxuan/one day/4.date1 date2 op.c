#include<stdio.h>
int main()
{
	int date1,date2,nu;
	char op;
	printf("请输入二则运算式：\n");
	scanf("%d%c%d",&date1,&op,&date2);
	if(op=='+')
		nu=date1+date2;
	else if(op=='*')
		nu=date1*date2;
	else if(op=='-')
		nu=date1-date2;
	else
		nu=date1/date2;
	
	printf("%d\n",nu); 
		
}
