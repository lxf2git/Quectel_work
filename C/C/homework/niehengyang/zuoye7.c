#include<stdio.h>
int main()
{
	char i;
	int a=0,b=0,c=0,d=0;
	printf("请输入字符串：");
	i=getchar();
	for(;i!='\n';)
	{
	if((i>=65&&i<=90)||(i>=97&&i<=122))
		
		a++;

	else	if((i>=48)&&(i<=57))
		
			b++;
	else	if(i==32)
			
				c++;
			
	else
	{
		d++;
	}
//	printf("统计得出：字母有%d个；数字有%d个；空格有%d个；其余有%d个。\n",a,b,c,d);
	i=getchar();
	if(i==10)
	{
	printf("统计得出：字母有%d个；数字有%d个；空格有%d个；其余有%d个。\n",a,b,c,d);
	}
	}
}
