#include<stdio.h>

int main()
{	
	char ch; 
	int a;
	int en,sp,mt,ot,all;
	sp=0;
	en=0;
	mt=0;
	ot=0;
	all=0;
	printf("请输入字符串:\n");
	for(;a!=10;)
	{
		scanf("%c",&ch);
		a=ch;
		if(a==32)sp++;
		else if((a>=65&&a<=90)||(a>=97&&a<=122))en++;
		else if(a>=48&&a<=57)mt++;
		else ot++;
	}
	ot=ot-1;
	all=sp+en+mt+ot;
	printf("字母%d个\n空格%d个\n数字%d个\n其他%d个\n总共%d个\n",en,sp,mt,ot,all);	

	return 0;
}
