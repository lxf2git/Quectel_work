#include<stdio.h>

int main()
{
	char ch;
	double s;
	int num=0,c=0,space=0,other=0;
	int a;
	printf("请输入一串字符串：（包括最后一次回车）以回车结束：\n");
	for(;a != 10;)
	{
		scanf("%c",&ch);
		a=ch;
	    if((a>=65 && a<=90) || (a>=97 && a<=122) )
				c++;
		else if(a>=48 && a<=57)
				num++;
		else if(a == 32)
				space++;
		else
				other++;
	}
	printf("输入的字符有%d个，数字有%d个，空格有%d个，其他的有%d个！！\n",c, num, space, other);
	return 0;
}
