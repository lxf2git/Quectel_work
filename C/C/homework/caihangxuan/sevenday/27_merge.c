#include<stdio.h> 
int main()
{
	int a,b,i,unit,decade,hundreds,kilobit;//个，十，百，千
	printf("请输入二位正整数a。");
	scanf("%d",&a);
	printf("请输入二位正整数b。");
	scanf("%d",&b);
	unit=a%10;
	a=a/10;
	hundreds=a%10;
	decade=b%10;
	b=b/10;
	kilobit=b%10;
	i=unit+decade*10+hundreds*100+kilobit*1000;
	printf("%d\n",i);
}
