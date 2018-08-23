#include<stdio.h>
int main()
{
	int date1,date2,z;
	char op,ch;
	printf("请输入两个数：\n");
	scanf("%d,%d",&date1,&date2);
	ch=getchar();
	scanf("%c",&op);
	if(op=='+')		
			printf("结果是:%d\n",date1 + date2);
	else if(op=='-')
			printf("结果是:%d\n",date1 - date2);
	else if(op=='*')
			printf("结果是:%d\n",date1 * date2);
	else if(op=='/')
			printf("结果是:%d\n",date1 / date2);
	else
			printf("error");
	return 0;
}
